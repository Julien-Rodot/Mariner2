/**
 * @name Object.h
 * @author jj
 * @brief The camera where the player sees.
 */

#include "Objects/m_Camera.h"
#include "Services/m_RunService.h"
#include "Services/m_Workspace.h"

namespace Mariner {
    
    namespace Objects {

        m_Camera* m_CameraThisPointer = nullptr;

        m_Camera* m_Camera::New() {

            m_Camera* Instance = new m_Camera();
            Instance->Name = "Camera";
            Instance->ClassName = "m_Camera";
            Instance->Position = Mariner::Libraries::m_Vector3D::New(0,0,3);
            m_CameraThisPointer = Instance;
            Instance->CameraRunLoop();
            return Instance;

        }

        Mariner::Libraries::m_Matrix<double> m_Camera::CreateViewMatrix(const Mariner::Libraries::m_Vector3D& position, const Mariner::Libraries::m_Vector3D& front,  const Mariner::Libraries::m_Vector3D& up) {

            auto dot = [](const auto& a, const auto& b) -> double {

                return a.x * b.x + a.y * b.y + a.z * b.z;

            };

            auto cross = [](const auto& a, const auto& b) -> Mariner::Libraries::m_Vector3D {

                return Mariner::Libraries::m_Vector3D::New(

                    a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x

                );

            };

            auto normalize = [](const auto& v) -> Mariner::Libraries::m_Vector3D {

                double len = std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);

                if (len == 0) {

                    return Mariner::Libraries::m_Vector3D::New(0,0,0);

                }

                return Mariner::Libraries::m_Vector3D::New(v.x/len, v.y/len, v.z/len);

            };

            Mariner::Libraries::m_Vector3D f = normalize(front);
            Mariner::Libraries::m_Vector3D r = normalize(cross(f, up));
            Mariner::Libraries::m_Vector3D u = cross(r, f);

            double px = -dot(r, position);
            double py = -dot(u, position);
            double pz = dot(f, position);

            Mariner::Libraries::m_Matrix<double> view = {

                {r.x, u.x, -f.x, 0},
                {r.y, u.y, -f.y, 0},
                {r.z, u.z, -f.z, 0},
                {px,  py,  pz,  1}

            };

            return view;
        }

        Mariner::Libraries::m_Matrix<double> m_Camera::CreateProjectionMatrix(double fov, double aspect, double near, double far) {

            double f = 1.0 / tan(fov / 2.0);

            Mariner::Libraries::m_Matrix<double> proj = {

                {f/aspect, 0, 0, 0},
                {0, f, 0, 0},
                {0, 0, (far+near)/(near-far), -1},
                {0, 0, (2*far*near)/(near-far), 0}

            };

            return proj;

        }
        
        void m_Camera::CameraRunLoop() {

            auto RunService = Mariner::Services::m_RunService::New();
            auto Workspace = Mariner::Services::m_Workspace::New();

            RunService->PreRender.Connect([Workspace](){

                if(m_CameraThisPointer->CameraSubject) {

                    m_CameraThisPointer->Position = m_CameraThisPointer->CameraSubject->Position;

                }

                // this is for now...
                double aspect = 16.0 / 9.0;
                double fov = 90.0 * M_PI / 180.0;
                double near = 0.1;
                double far = 100.0;

                m_CameraThisPointer->ViewMatrix = m_CameraThisPointer->CreateViewMatrix(m_CameraThisPointer->Position, m_CameraThisPointer->Front, m_CameraThisPointer->Up);
                m_CameraThisPointer->ProjectionMatrix = m_CameraThisPointer->CreateProjectionMatrix(fov, aspect, near, far);


            });

        };
        
    } // namespace Objects
    
} // namespace Mariner
