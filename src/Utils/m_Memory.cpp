/**
 * @name Memory.cpp
 * @brief Safe memory functions.
 * @author jj
 */

#include "Utils/m_Memory.h"

namespace Mariner {

    namespace Utils {

        void* m_Memory::malloc(size_t Size) {

            vm_map_t Self = mach_task_self();
            mach_vm_address_t Address = 0;

            kern_return_t Result = mach_vm_allocate(Self, &Address, Size, VM_FLAGS_ANYWHERE);

            if(Result != KERN_SUCCESS) {

                // TODO: Replace with app crash.
                return nullptr;

            };

            return reinterpret_cast<void*>(Address);

        };

        void m_Memory::free() {

            // TODO: Implement once we have table libs.
            

        };

    } // namespace Utils

} // namespace Mariner