#include "App/m_Application.hpp"

namespace Mariner::Internal {

    void m_Entry() {

        m_Application* Application = new m_Application();
        Application->m_Application_Start();

    }

}
