/**
 * @name TaskScheduler.h
 * @author jj
 * @brief The engine scheduler.
 */

//FIXME: This is horribly slow. o(n^2) (quadratic). Fix this shit.

#include "Services/m_TaskScheduler.h"
#include "Objects/m_Thread.h"

static uint32_t Seed = 123456789;

namespace Mariner {

    namespace Services {

        m_TaskScheduler* m_TaskScheduler::New() {

            static m_TaskScheduler* Instance = new m_TaskScheduler();
            Instance->Name = "TaskScheduler";
            Instance->ClassName = "m_TaskScheduler";
            return Instance;

        }

        void m_TaskScheduler::ExecuteAllThreads() {

            while (!Mariner::Libraries::m_Array<Mariner::Objects::m_Job*>::IsEmpty(JobsToAssign)) {

                for(auto* Job : this->JobsToAssign) {

                    if(Job->ThreadToExecute == "") {

                        continue;

                    }

                    for(auto* Thread : this->ThreadsAvailable) {

                        if(Job->ThreadToExecute == Thread->Name) {

                            Mariner::Libraries::m_Array<Mariner::Objects::m_Job*>::Add(Thread->JobsToExecute, Job);

                        }

                    }

                    for(auto* Thread : this->ThreadsAvailable) {

                        Thread->ExecuteAllJobs();
                        Mariner::Libraries::m_Array<Mariner::Objects::m_Job*>::Clear(Thread->JobsToExecute);

                    }

                }

                Mariner::Libraries::m_Array<Mariner::Objects::m_Job*> CyclicJobs = {};

                for(auto* Job: this->JobsToAssign) {

                    if(Job->Cyclic) {

                        Mariner::Libraries::m_Array<Mariner::Objects::m_Job*>::Add(CyclicJobs, Job);
                        
                    }

                }

                JobsToAssign = CyclicJobs;

            }
                       
        }

        void m_TaskScheduler::AddJob(Mariner::Objects::m_Job* JobToAdd) {

            Mariner::Libraries::m_Array<Mariner::Objects::m_Job*>::Add(this->JobsToAssign, JobToAdd);

        }

        void m_TaskScheduler::AddThread(Mariner::Objects::m_Thread* ThreadToAdd) {

            Mariner::Libraries::m_Array<Mariner::Objects::m_Thread*>::Add(this->ThreadsAvailable, ThreadToAdd);

        }

    } // namespace Services
    
} // namespace Mariner
