#pragma once

/**
 * @name m_Thread.h
 * @author jj
 * @brief The basic thread.
 */

#include <functional>
#include <thread>
#include <chrono>
#include <pthread.h>
#include <mutex>

#include "Objects/m_Object.h"
#include "Libraries/m_String.h"
#include "Libraries/m_Array.h"
#include "Objects/m_Job.h"
#include "Services/m_TaskScheduler.h"

namespace Mariner {
    
    namespace Objects {

        class m_Thread : public m_Object {

            public:

                static m_Thread* New();

                void SetThread(pthread_t ThreadToSet);
                bool ExecuteAllJobs();

            protected:

                m_Thread() = default;
                virtual ~m_Thread() = default;

            private:

            friend class Mariner::Services::m_TaskScheduler;
            pthread_t Thread;
            Libraries::m_Array<m_Job*> JobsToExecute = {};
            std::mutex JobsMutex;

        };
        
    } // namespace Objects
    
} // namespace Mariner



