/**
 * @name m_Thread.h
 * @author jj
 * @brief The basic thread.
 */

#include "Objects/m_Thread.h"

namespace Mariner {

    namespace Objects {

        m_Thread* m_Thread::New() {

            m_Thread* Instance = new m_Thread();
            Instance->Name = "Thread";
            Instance->ClassName = "m_Thread";
            return Instance;

        }

        static void* m_ThreadEntry(void* Arg) {

            auto* Data = static_cast<std::pair<Mariner::Libraries::m_Array<m_Job*>, Mariner::Libraries::m_String>*>(Arg);

            pthread_setname_np(Mariner::Libraries::m_String::ToCString(Data->second));

            for (auto* Job : Data->first) {

                if (Job && Job->FunctionPointer) {

                    Job->FunctionPointer();

                }

            }

            delete Data;
            return nullptr;

        }

        bool m_Thread::ExecuteAllJobs() {

            Mariner::Libraries::m_Array<m_Job*> LocalJobs;

            {
                
                std::lock_guard<std::mutex> lock(JobsMutex);
                LocalJobs = JobsToExecute;
                Mariner::Libraries::m_Array<m_Job*>::Clear(JobsToExecute);

            }

            if (pthread_equal(Thread, pthread_self())) {

                for (auto* Job : LocalJobs) {

                    if (Job && Job->FunctionPointer) {

                        Job->FunctionPointer();

                    }
                }

                return true;
            }

            auto* Payload = new std::pair<Mariner::Libraries::m_Array<m_Job*>, Mariner::Libraries::m_String>(

                std::move(LocalJobs),
                Name

            );

            pthread_create(&Thread, nullptr, m_ThreadEntry, Payload);
            pthread_join(Thread, nullptr);

            return true;
        }


        void m_Thread::SetThread(pthread_t ThreadToSet) {

            Thread = ThreadToSet;

        }

    } // namespace Objects
    
} // namespace Mariner


