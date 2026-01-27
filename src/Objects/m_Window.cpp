/**
 * @name m_Window.cpp
 * @author jj
 * @brief The basic Window.
 */

#include "Objects/m_Window.h"
#include "Objects/m_DataModel.h"
#include "Services/m_TaskScheduler.h"
#include "Services/m_RunService.h"
#include "Services/m_MemStorageService.h"

auto DataModel = Mariner::Objects::m_DataModel::New();
auto RunService = Mariner::Services::m_RunService::New();
auto TaskScheduler = Mariner::Services::m_TaskScheduler::New();

namespace Mariner {

    namespace Objects {

        void m_Window::WindowLoop() {

            auto MemStorageService = Mariner::Services::m_MemStorageService::New();

            GLFWwindow* WindowPointer = MemStorageService->Load<GLFWwindow*>("m_EngineWindowPointer");

            if(glfwWindowShouldClose(WindowPointer)) {

                RunService->Stop();

            }

            glfwSwapBuffers(WindowPointer);

        };

        m_Window* m_Window::New() {

            static m_Window* Instance = new m_Window();
            Instance->Name = "Window";
            Instance->ClassName = "m_Window";
            return Instance;    

        }

        void m_Window::CreateWindow() {

            auto MemStorageService = Mariner::Services::m_MemStorageService::New();

            glfwInit();

            GLFWwindow* WindowPointer = glfwCreateWindow(this->SizeX, this->SizeY, Mariner::Libraries::m_String::ToCString(DataModel->Name), NULL, NULL);
            if(!WindowPointer) {

                throw std::runtime_error("Oh shit! Mariner could not create a window!");

            }

            Mariner::Objects::m_Job* WindowJob = Mariner::Objects::m_Job::New();
            WindowJob->FunctionPointer = this->WindowLoop;
            WindowJob->Cyclic = true;
            WindowJob->ThreadToExecute = "m_MainThread";
            TaskScheduler->AddJob(WindowJob);
            
            MemStorageService->Store("m_EngineWindowPointer", WindowPointer);
            this->GLFWWindowPointer = WindowPointer;
            return;

        };
        
    } // namespace Objects
    
} // namespace Mariner


