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

        m_MessageBusService* MsgBusSrvThisPointer = nullptr;

        void m_MessageBusService::m_MessageBusServiceKeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

            if (action != GLFW_PRESS) return;

            bool shift = mods & GLFW_MOD_SHIFT;

            switch (key) {

                // Letters
                case GLFW_KEY_A: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_A")); break;
                case GLFW_KEY_B: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_B")); break;
                case GLFW_KEY_C: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_C")); break;
                case GLFW_KEY_D: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_D")); break;
                case GLFW_KEY_E: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_E")); break;
                case GLFW_KEY_F: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F")); break;
                case GLFW_KEY_G: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_G")); break;
                case GLFW_KEY_H: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_H")); break;
                case GLFW_KEY_I: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_I")); break;
                case GLFW_KEY_J: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_J")); break;
                case GLFW_KEY_K: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_K")); break;
                case GLFW_KEY_L: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_L")); break;
                case GLFW_KEY_M: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_M")); break;
                case GLFW_KEY_N: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_N")); break;
                case GLFW_KEY_O: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_O")); break;
                case GLFW_KEY_P: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_P")); break;
                case GLFW_KEY_Q: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_Q")); break;
                case GLFW_KEY_R: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_R")); break;
                case GLFW_KEY_S: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_S")); break;
                case GLFW_KEY_T: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_T")); break;
                case GLFW_KEY_U: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_U")); break;
                case GLFW_KEY_V: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_V")); break;
                case GLFW_KEY_W: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_W")); break;
                case GLFW_KEY_X: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_X")); break;
                case GLFW_KEY_Y: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_Y")); break;
                case GLFW_KEY_Z: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_Z")); break;

                // Numbers + Shift symbols
                case GLFW_KEY_1: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_EXCLAMATION" : "m_MsgBusSrv_KeyPress_1")); break;
                case GLFW_KEY_2: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_AT" : "m_MsgBusSrv_KeyPress_2")); break;
                case GLFW_KEY_3: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_HASH" : "m_MsgBusSrv_KeyPress_3")); break;
                case GLFW_KEY_4: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_DOLLAR" : "m_MsgBusSrv_KeyPress_4")); break;
                case GLFW_KEY_5: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_PERCENT" : "m_MsgBusSrv_KeyPress_5")); break;
                case GLFW_KEY_6: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_CARET" : "m_MsgBusSrv_KeyPress_6")); break;
                case GLFW_KEY_7: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_AMPERSAND" : "m_MsgBusSrv_KeyPress_7")); break;
                case GLFW_KEY_8: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_ASTERISK" : "m_MsgBusSrv_KeyPress_8")); break;
                case GLFW_KEY_9: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_LEFT_PAREN" : "m_MsgBusSrv_KeyPress_9")); break;
                case GLFW_KEY_0: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_RIGHT_PAREN" : "m_MsgBusSrv_KeyPress_0")); break;

                // Punctuation / Symbols + Shift variants
                case GLFW_KEY_MINUS: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_UNDERSCORE" : "m_MsgBusSrv_KeyPress_MINUS")); break;
                case GLFW_KEY_EQUAL: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_PLUS" : "m_MsgBusSrv_KeyPress_EQUAL")); break;
                case GLFW_KEY_LEFT_BRACKET: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_LEFT_CURLY" : "m_MsgBusSrv_KeyPress_LEFT_BRACKET")); break;
                case GLFW_KEY_RIGHT_BRACKET: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_RIGHT_CURLY" : "m_MsgBusSrv_KeyPress_RIGHT_BRACKET")); break;
                case GLFW_KEY_BACKSLASH: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_PIPE" : "m_MsgBusSrv_KeyPress_BACKSLASH")); break;
                case GLFW_KEY_SEMICOLON: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_COLON" : "m_MsgBusSrv_KeyPress_SEMICOLON")); break;
                case GLFW_KEY_APOSTROPHE: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_QUOTE" : "m_MsgBusSrv_KeyPress_APOSTROPHE")); break;
                case GLFW_KEY_COMMA: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_LESS" : "m_MsgBusSrv_KeyPress_COMMA")); break;
                case GLFW_KEY_PERIOD: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_GREATER" : "m_MsgBusSrv_KeyPress_PERIOD")); break;
                case GLFW_KEY_SLASH: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_QUESTION" : "m_MsgBusSrv_KeyPress_SLASH")); break;
                case GLFW_KEY_GRAVE_ACCENT: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String(shift ? "m_MsgBusSrv_KeyPress_TILDE" : "m_MsgBusSrv_KeyPress_GRAVE_ACCENT")); break;

                // Function keys
                case GLFW_KEY_LEFT_SHIFT: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_LEFT_SHIFT")); break;
                case GLFW_KEY_RIGHT_SHIFT: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_RIGHT_SHIFT")); break;
                case GLFW_KEY_ESCAPE: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_ESCAPE")); break;
                case GLFW_KEY_ENTER: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_ENTER")); break;
                case GLFW_KEY_TAB: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_TAB")); break;
                case GLFW_KEY_BACKSPACE: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_BACKSPACE")); break;
                case GLFW_KEY_SPACE: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_SPACE")); break;
                case GLFW_KEY_INSERT: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_INSERT")); break;
                case GLFW_KEY_DELETE: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_DELETE")); break;
                case GLFW_KEY_RIGHT: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_RIGHT")); break;
                case GLFW_KEY_LEFT: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_LEFT")); break;
                case GLFW_KEY_DOWN: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_DOWN")); break;
                case GLFW_KEY_UP: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_UP")); break;
                case GLFW_KEY_PAGE_UP: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_PAGE_UP")); break;
                case GLFW_KEY_PAGE_DOWN: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_PAGE_DOWN")); break;
                case GLFW_KEY_HOME: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_HOME")); break;
                case GLFW_KEY_END: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_END")); break;
                case GLFW_KEY_CAPS_LOCK: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_CAPS_LOCK")); break;
                case GLFW_KEY_SCROLL_LOCK: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_SCROLL_LOCK")); break;
                case GLFW_KEY_NUM_LOCK: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_NUM_LOCK")); break;
                case GLFW_KEY_PRINT_SCREEN: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_PRINT_SCREEN")); break;
                case GLFW_KEY_PAUSE: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_PAUSE")); break;

                // F1-F25
                case GLFW_KEY_F1:  MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F1")); break;
                case GLFW_KEY_F2:  MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F2")); break;
                case GLFW_KEY_F3:  MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F3")); break;
                case GLFW_KEY_F4:  MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F4")); break;
                case GLFW_KEY_F5:  MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F5")); break;
                case GLFW_KEY_F6:  MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F6")); break;
                case GLFW_KEY_F7:  MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F7")); break;
                case GLFW_KEY_F8:  MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F8")); break;
                case GLFW_KEY_F9:  MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F9")); break;
                case GLFW_KEY_F10: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F10")); break;
                case GLFW_KEY_F11: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F11")); break;
                case GLFW_KEY_F12: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F12")); break;
                case GLFW_KEY_F13: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F13")); break;
                case GLFW_KEY_F14: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F14")); break;
                case GLFW_KEY_F15: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F15")); break;
                case GLFW_KEY_F16: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F16")); break;
                case GLFW_KEY_F17: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F17")); break;
                case GLFW_KEY_F18: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F18")); break;
                case GLFW_KEY_F19: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F19")); break;
                case GLFW_KEY_F20: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F20")); break;
                case GLFW_KEY_F21: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F21")); break;
                case GLFW_KEY_F22: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F22")); break;
                case GLFW_KEY_F23: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F23")); break;
                case GLFW_KEY_F24: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F24")); break;
                case GLFW_KEY_F25: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_F25")); break;

                // Numpad
                case GLFW_KEY_KP_0: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_0")); break;
                case GLFW_KEY_KP_1: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_1")); break;
                case GLFW_KEY_KP_2: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_2")); break;
                case GLFW_KEY_KP_3: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_3")); break;
                case GLFW_KEY_KP_4: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_4")); break;
                case GLFW_KEY_KP_5: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_5")); break;
                case GLFW_KEY_KP_6: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_6")); break;
                case GLFW_KEY_KP_7: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_7")); break;
                case GLFW_KEY_KP_8: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_8")); break;
                case GLFW_KEY_KP_9: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_9")); break;
                case GLFW_KEY_KP_DECIMAL: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_DECIMAL")); break;
                case GLFW_KEY_KP_DIVIDE: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_DIVIDE")); break;
                case GLFW_KEY_KP_MULTIPLY: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_MULTIPLY")); break;
                case GLFW_KEY_KP_SUBTRACT: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_SUBTRACT")); break;
                case GLFW_KEY_KP_ADD: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_ADD")); break;
                case GLFW_KEY_KP_ENTER: MsgBusSrvThisPointer->OnIncommingMessage.Fire(Mariner::Libraries::m_String("m_MsgBusSrv_KeyPress_KP_ENTER")); break;

                default: break;
            }

        }

        m_MessageBusService* m_MessageBusService::New() {

            auto MemStorageService = Mariner::Services::m_MemStorageService::New();

            static m_MessageBusService* Instance =  new m_MessageBusService();
            Instance->Name = "MessageBusService";
            Instance->ClassName = "m_MessageBusService";
            MsgBusSrvThisPointer = Instance;

            glfwSetKeyCallback(MemStorageService->Load<GLFWwindow*>("m_EngineWindowPointer"), m_MessageBusServiceKeyboardCallback);

            return Instance;

        }

    } // namespace Services

} // namespace Mariner
