#pragma once

/**
 * @name m_Window.h
 * @author jj
 * @brief The basic Window.
 */

#include <string.h>
#include <exception>

#include "GLFW/glfw3.h"
#include "Objects/m_Object.h"
#include "Libraries/m_String.h"

namespace Mariner {
    
    namespace Objects {

        class m_Window : public m_Object {

            public:

                static m_Window* New();

                uint16_t SizeX;
                uint16_t SizeY;

                void CreateWindow();
            
            protected:

                m_Window() = default;
                virtual ~m_Window() = default;

            private:

                GLFWwindow* GLFWWindowPointer = nullptr;
                static void WindowLoop();

        };
        
    } // namespace Objects
    
} // namespace Mariner



