/**
 * @name Vector3D.h
 * @author jj
 * @brief A type that describes the position, rotation and size of an object in
 * the world.
 */

#include "Libraries/m_Vector3D.h"

namespace Mariner {
    
    namespace Libraries {

        m_Vector3D m_Vector3D::New(float x, float y, float z) {

            m_Vector3D* Vector = new m_Vector3D();
            Vector->x = x;
            Vector->y = y;
            Vector->z = z;
            return *Vector;
        
        }


    } // namespace Libraries
    
} // namespace Mariner

