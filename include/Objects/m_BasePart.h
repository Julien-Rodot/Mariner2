#pragma once

/**
 * @name BasePart.h
 * @author jj
 * @brief The basic part in Mariner.
 */

#include "Objects/m_Object.h"
#include "Libraries/m_Vector3D.h"

namespace Mariner {
    
    namespace Objects {

        class m_BasePart : public Mariner::Objects::m_Object {

            public:

                static m_BasePart* New();
                Mariner::Libraries::m_Vector3D Position;
               
            protected:

                m_BasePart() = default;
                virtual ~m_BasePart() = default;

            private:

        };
        
    } // namespace Objects
    
} // namespace Mariner
