#pragma once

/**
 * @name RunState.h
 * @author jj
 * @brief RunState
 */

#include <stdint.h>

namespace Mariner
{
    namespace Enums
    {

        enum class m_RunState : uint8_t {

            Running = 0,
            Paused = 1,
            Stopped = 2,

        } ;
        
    } // namespace Enums
    
} // namespace Mariner
