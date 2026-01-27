#pragma once

/**
 * @name TaskScheduler.h
 * @author jj
 * @brief The engine scheduler.
 */

#include <random>

#include "Objects/m_Object.h"
#include "Libraries/m_String.h"
#include "Libraries/m_Array.h"
#include "Objects/m_Job.h"

namespace Mariner {

    namespace Services {

        class m_TaskScheduler : public Mariner::Objects::m_Object {

            public:

                static m_TaskScheduler* New();

                void AddJob(Mariner::Objects::m_Job* Job);
                void AddThread(Mariner::Objects::m_Thread* Thread);

                void ExecuteAllThreads();

            protected:

                m_TaskScheduler() = default;
                virtual ~m_TaskScheduler() = default;

            private:

                Libraries::m_Array<Mariner::Objects::m_Job*> JobsToAssign = {};
                Libraries::m_Array<Mariner::Objects::m_Thread*> ThreadsAvailable = {};

        }; 

    } // namespace Services

} // namespace Mariner
