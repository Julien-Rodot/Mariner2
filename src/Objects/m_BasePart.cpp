/**
 * @name BasePart.h
 * @author jj
 * @brief The basic part in Mariner.
 */

#include "Objects/m_BasePart.h"

namespace Mariner {
    
    namespace Objects {
        
        m_BasePart* m_BasePart::New() {

            static m_BasePart* Instance = new m_BasePart();
            Instance->Name = "BasePart";
            Instance->ClassName = "m_BasePart";
            return Instance;

        }

    } // namespace Objects
    
} // namespace Mariner
