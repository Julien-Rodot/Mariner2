#pragma once

/**
 * @name Workspace.h
 * @author jj
 * @brief The entire 3D view of the game. All parts, meshparts, etc lives here.
 */

#include "Objects/m_Object.h"

namespace Mariner {

    namespace Objects {

        class m_Camera;

    }

    namespace Services {

        class m_Workspace : public Mariner::Objects::m_Object {

            public:

                static m_Workspace* New();

                Mariner::Objects::m_Camera* CurrrentCamera = nullptr;

            protected:

                m_Workspace() = default;
                virtual ~m_Workspace() = default;

            private:

                void WorkspaceFunction();

        };

    } // namespace Services
    
} // namespace Mariner
