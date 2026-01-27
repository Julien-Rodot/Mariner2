/**
 * @name RunService.h
 * @author jj
 * @brief The engine looping system.
 */

#include "Services/m_RunService.h"
#include "Services/m_TaskScheduler.h"

static Mariner::Services::m_TaskScheduler* TaskScheduler = Mariner::Services::m_TaskScheduler::New();


namespace Mariner {

    namespace Services {

        m_RunService* ThisPointer = nullptr;

        m_RunService* m_RunService::New() {

            static m_RunService* Instance = new m_RunService();
            Instance->Name = "RunService";
            Instance->ClassName = "m_RunService";
            return Instance;

        }

        void m_RunService::RunServiceFunction() {
            
            ThisPointer->PreSimulation.Fire();
            glfwPollEvents();
            ThisPointer->PostSimulation.Fire();
            ThisPointer->PreRender.Fire();
            ThisPointer->RenderStepped.Fire();
            ThisPointer->PostRender.Fire();
            ThisPointer->Heartbeat.Fire();

        }

        void m_RunService::Run() {

            this->RunState = Mariner::Enums::m_RunState::Running;
            ThisPointer = this;

            RunServiceJob->Cyclic = true;
            RunServiceJob->FunctionPointer = RunServiceFunction;
            RunServiceJob->ThreadToExecute = "m_MainThread";

            TaskScheduler->AddJob(this->RunServiceJob);
            TaskScheduler->ExecuteAllThreads();

        }

        void m_RunService::Pause() {

            this->RunState = Mariner::Enums::m_RunState::Paused;

        }

        void m_RunService::Stop() {

            this->RunState = Mariner::Enums::m_RunState::Stopped;
            exit(0);
            
        }

    }

}