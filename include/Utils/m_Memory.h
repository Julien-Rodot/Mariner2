#pragma once

/**
 * @name Memory.h
 * @brief Safe memory functions.
 * @author jj
 */

#include <string.h>
#include <mach/mach_vm.h> 
#include <mach/mach.h>
#include <mach/task.h> 

namespace Mariner {

    namespace Utils {

        class m_Memory {

            public:

                static void* malloc(size_t Size);
                static void free();

            private:

        };

    } // namespace Utils
    
} // namespace Mariner
