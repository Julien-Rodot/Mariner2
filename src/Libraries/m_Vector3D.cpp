/**
 * @name Vector3D.h
 * @author jj
 * @brief A type that describes the position, rotation and size of an object in
 * the world.
 */

#include "Libraries/m_Vector3D.h"

namespace Mariner {
    
    namespace Libraries {

        m_Vector3DLib* m_Vector3DLib::OpenLibrary() {

            return new m_Vector3DLib();

        };
        
    } // namespace Libraries
    
} // namespace Mariner

