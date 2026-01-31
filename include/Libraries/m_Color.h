#pragma once

/**
 * @param name MColor.hpp
 * @author jj
 * @brief The color lib
 */

#include "Mariner/MarinerTypes.h"

namespace Mariner {
    
    namespace Libraries {
        
        class m_Color {

            public:

                Mariner::Types::m_Half R;
                Mariner::Types::m_Half G;
                Mariner::Types::m_Half B;

                static m_Color FromRGB(Mariner::Types::m_Half R, Mariner::Types::m_Half G, Mariner::Types::m_Half B);

                m_Color() = default;
                virtual ~m_Color() = default;

            protected:

            private:

        };

    } // namespace Libraries
    
} // namespace Mariner
