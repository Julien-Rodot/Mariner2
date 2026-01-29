#pragma once

/**
 * @name Object.h
 * @author jj
 * @brief The camera where the player sees.
 */

#include "Objects/m_Object.h"
#include "Objects/m_BasePart.h"
#include "Libraries/m_Vector3D.h"

namespace Mariner {
    
    namespace Objects {

        class m_Camera : public Mariner::Objects::m_Object {

            public:

                static m_Camera* New();

                Mariner::Libraries::m_Vector3D Position;
                Mariner::Libraries::m_Vector3D Front = Mariner::Libraries::m_Vector3D::New(0,0,-1);
                Mariner::Libraries::m_Vector3D Up = Mariner::Libraries::m_Vector3D::New(0,1,0);

                Mariner::Objects::m_BasePart* CameraSubject = nullptr;

            protected:

                m_Camera() = default;
                virtual ~m_Camera() = default;

            private:

                static void CameraRunLoop();

        };
        
    } // namespace Objects
    
} // namespace Mariner
