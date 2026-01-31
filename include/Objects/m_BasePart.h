#pragma once

/**
 * @name BasePart.h
 * @author jj
 * @brief The basic part in Mariner.
 */

#include "Objects/m_Object.h"
#include "Libraries/m_Vector3D.h"
#include "Libraries/m_Matrix.h"
#include "Libraries/m_Array.h"
#include "Libraries/m_Color.h"

namespace Mariner {
    
    namespace Objects {

        class m_BasePart : public Mariner::Objects::m_Object {

            public:

                static m_BasePart* New();
                Mariner::Libraries::m_Vector3D Position;
                Mariner::Libraries::m_Color Color = Mariner::Libraries::m_Color::FromRGB(0.2,0.2,0.2);

                Mariner::Libraries::m_Array<long long> Vertecies = {};
                Mariner::Libraries::m_Array<long long> Triangles = {};
                
            protected:

                m_BasePart() = default;
                virtual ~m_BasePart() = default;

            private:


        };
        
    } // namespace Objects
    
} // namespace Mariner
