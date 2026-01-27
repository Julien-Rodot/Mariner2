/**
 * @param name MString.cpp
 * @author jj
 * @brief The instance lib. For objects, NOT SERVICES!
 */

#include "Libraries/m_Instance.h"

namespace Mariner {

    namespace Libraries {

        m_InstanceLib* m_InstanceLib::OpenLibrary() {

            static m_InstanceLib* Instance = new m_InstanceLib();
            return Instance;

        }
        
    } // namespace Libraries
    
} // namespace Mariner
