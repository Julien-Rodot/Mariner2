/**
 * @name MessageBusService.h
 * @author jj
 * @brief The engine's message bus. Used to communicate to engine scripts about
 * events that just took place in the engine context.
 */

#include "Services/m_MessageBusService.h"
#include "Services/m_MemStorageService.h"
#include <iostream>

namespace Mariner {
    
    namespace Services {

        void m_MessageBusService::m_MessageBusServiceKeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

            if (action != GLFW_PRESS) {
                
                return;

            }

            switch (key) {
                
                case GLFW_KEY_W:
                    std::cout << "W pressed\n";
                    break;

                case GLFW_KEY_A:
                    std::cout << "A pressed\n";
                    break;

                case GLFW_KEY_S:
                    std::cout << "S pressed\n";
                    break;

                case GLFW_KEY_D:
                    std::cout << "D pressed\n";
                    break;

                case GLFW_KEY_ESCAPE:
                    glfwSetWindowShouldClose(window, GLFW_TRUE);
                    break;

                default:
                    break;
            }
        }

        m_MessageBusService* m_MessageBusService::New() {

            auto MemStorageService = Mariner::Services::m_MemStorageService::New();

            static m_MessageBusService* Instance =  new m_MessageBusService();
            Instance->Name = "MessageBusService";
            Instance->ClassName = "m_MessageBusService";

            glfwSetKeyCallback(MemStorageService->Load<GLFWwindow*>("m_EngineWindowPointer"), m_MessageBusServiceKeyboardCallback);

            return Instance;

        }
        
    } // namespace Objects
    
} // namespace Mariner
