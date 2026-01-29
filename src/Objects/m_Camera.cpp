/**
 * @name Object.h
 * @author jj
 * @brief The camera where the player sees.
 */

#include "Objects/m_Camera.h"
#include "Services/m_RunService.h"

namespace Mariner {
    
    namespace Objects {

        m_Camera* m_Camera::New() {

            m_Camera* Instance = new m_Camera();
            Instance->Name = "Camera";
            Instance->ClassName = "m_Camera";
            Instance->Position = Mariner::Libraries::m_Vector3D::New(0,0,3);
            Instance->CameraRunLoop();
            return Instance;

        }
        
        void m_Camera::CameraRunLoop() {

            auto RunService = Mariner::Services::m_RunService::New();

            RunService->PreRender.Connect([](){

                

            });

        };
        
    } // namespace Objects
    
} // namespace Mariner
