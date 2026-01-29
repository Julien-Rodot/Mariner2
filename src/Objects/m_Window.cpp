/**
 * @name m_Window.cpp
 * @author jj
 * @brief The basic Window.
 */

#include <glad/glad.h>

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

            glfwMakeContextCurrent(WindowPointer);

            if(glfwWindowShouldClose(WindowPointer)) {

                RunService->Stop();

            }

            // if you see bright magenta smth horrible went wrong
            glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

            GLFWwindow* WindowPointer = glfwCreateWindow(this->SizeX, this->SizeY, Mariner::Libraries::m_String::ToCString(DataModel->Name), NULL, NULL);
            if(!WindowPointer) {

                throw std::runtime_error("Oh shit! Mariner could not create a window!");

            }

            glfwMakeContextCurrent(WindowPointer);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

                throw std::runtime_error("Oh fuck! Mariner coudnt get GLAD loaded!");

            }

            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LESS);

            glViewport(0, 0, this->SizeX, this->SizeY);

            Mariner::Objects::m_Job* WindowJob = Mariner::Objects::m_Job::New();
            WindowJob->FunctionPointer = this->WindowLoop;
            WindowJob->Cyclic = true;
            WindowJob->ThreadToExecute = "m_MainThread";
            TaskScheduler->AddJob(WindowJob);
            
            this->GLFWWindowPointer = WindowPointer;
            MemStorageService->Store("m_EngineWindowPointer", WindowPointer);

            return;

        };
        
    } // namespace Objects
    
} // namespace Mariner


