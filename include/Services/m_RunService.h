#pragma once

/**
 * @name RunService.h
 * @author jj
 * @brief controls the looops.
 */


#include <chrono>
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

                Mariner::Libraries::m_Signal<void> PreSimulation = *Mariner::Libraries::m_Signal<void>::New();
                Mariner::Libraries::m_Signal<void>  PostSimulation = *Mariner::Libraries::m_Signal<void>::New();
                Mariner::Libraries::m_Signal<void>  PreRender = *Mariner::Libraries::m_Signal<void>::New();
                Mariner::Libraries::m_Signal<void>  RenderStepped = *Mariner::Libraries::m_Signal<void>::New();
                Mariner::Libraries::m_Signal<void>  PostRender = *Mariner::Libraries::m_Signal<void>::New();
                Mariner::Libraries::m_Signal<float>  Heartbeat = *Mariner::Libraries::m_Signal<float>::New();

            protected:

                m_RunService() = default;
                virtual ~m_RunService() = default;

            private:

                Mariner::Objects::m_Job* RunServiceJob = Mariner::Objects::m_Job::New();

                static void RunServiceFunction();

        }; 

    } // namespace Services

} // namespace Mariner
