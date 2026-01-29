#pragma once

/**
 * @name MessageBusService.h
 * @author jj
 * @brief The engine's message bus. Used to communicate to engine scripts about
 * events that just took place in the engine context.
 */

#include <any>
#include "GLFW/glfw3.h"

#include "Objects/m_Object.h"
#include "Libraries/m_String.h"
#include "Libraries/m_Signal.h"

namespace Mariner {
    
    namespace Services {

        class m_MessageBusService : public Mariner::Objects::m_Object {

            public:

                static m_MessageBusService* New();

                void Call(Mariner::Libraries::m_String MessageId, ...);
                std::any GetLast(Mariner::Libraries::m_String MessageId);
                
                Mariner::Libraries::m_Signal<Mariner::Libraries::m_String> OnIncommingMessage = *Mariner::Libraries::m_Signal<Mariner::Libraries::m_String>::New();

            protected:

            private:

                m_MessageBusService() = default;
                virtual ~m_MessageBusService() = default;

                static void m_MessageBusServiceKeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
                static void m_MessageBusServiceCameraCallback();
                static void m_MessageBusServiceMouseCallback();
                static void m_MessageBusServiceMicCallback();
            
        };
        
    } // namespace Objects
    
} // namespace Mariner
