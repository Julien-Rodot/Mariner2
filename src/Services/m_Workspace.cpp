/**
 * @name Workspace.h
 * @author jj
 * @brief The entire 3D view of the game. All parts, meshparts, etc lives here.
 */

#include "Services/m_Workspace.h"
#include "Services/m_RunService.h"
#include "Objects/m_Camera.h"

namespace Mariner {

    namespace Services {

        m_Workspace* m_WorkspaceThisPointer = nullptr;

        m_Workspace* m_Workspace::New() {

            static m_Workspace* Instance = new m_Workspace();
            Instance->Name = "Workspace";
            Instance->ClassName = "m_Workspace";
            m_WorkspaceThisPointer = Instance;
            Instance->WorkspaceFunction();
            return Instance;

        };

        void m_Workspace::WorkspaceFunction() {

            auto RunService =  Mariner::Services::m_RunService::New();
            RunService->PreRender.Connect([](){

                if(!m_WorkspaceThisPointer->FindFirstChildOfClass("m_Camera")) {

                    Mariner::Objects::m_Camera* Camera = Mariner::Objects::m_Camera::New();
                    Camera->SetParent(m_WorkspaceThisPointer);
                    m_WorkspaceThisPointer->CurrrentCamera = Camera;

                };

            });

        }
        
    } // namespace Services
    
} // namespace Mariner
