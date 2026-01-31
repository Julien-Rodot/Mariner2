/**
 * @param name MColor.cpp
 * @author jj
 * @brief The color lib
 */


#include "Libraries/m_Color.h"

namespace Mariner {
    
    namespace Libraries {

        m_Color m_Color::FromRGB(Mariner::Types::m_Half R, Mariner::Types::m_Half G, Mariner::Types::m_Half B) {

            m_Color* Instance = new m_Color();
            Instance->R = R;
            Instance->G = G;
            Instance->B = B;
            return *Instance;

        }
        
    } // namespace Libraries
    
} // namespace Mariner
