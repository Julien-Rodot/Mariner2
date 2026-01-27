#pragma once

/**
 * @name RunService.h
 * @author jj
 * @brief controls the looops.
 */


#include "GLFW/glfw3.h"

#include "Objects/m_Object.h"
#include "Libraries/m_String.h"
#include "Libraries/m_Array.h"
#include "Libraries/m_Signal.h"
#include "Objects/m_Job.h"
#include "Enums/m_RunState.h"
#include "Objects/m_Window.h"

namespace Mariner {

    namespace Services {

        class m_RunService : public Mariner::Objects::m_Object {

            public:

                static m_RunService* New();
                Mariner::Enums::m_RunState RunState = Mariner::Enums::m_RunState::Stopped;

                void Run();
                void Pause();
                void Stop();

                Mariner::Libraries::m_Signal PreSimulation = *Mariner::Libraries::m_Signal::New();
                Mariner::Libraries::m_Signal PostSimulation = *Mariner::Libraries::m_Signal::New();
                Mariner::Libraries::m_Signal PreRender = *Mariner::Libraries::m_Signal::New();
                Mariner::Libraries::m_Signal RenderStepped = *Mariner::Libraries::m_Signal::New();
                Mariner::Libraries::m_Signal PostRender = *Mariner::Libraries::m_Signal::New();
                Mariner::Libraries::m_Signal Heartbeat = *Mariner::Libraries::m_Signal::New();

            protected:

                m_RunService() = default;
                virtual ~m_RunService() = default;

            private:

                Mariner::Objects::m_Job* RunServiceJob = Mariner::Objects::m_Job::New();

                static void RunServiceFunction();

        }; 

    } // namespace Services

} // namespace Mariner
