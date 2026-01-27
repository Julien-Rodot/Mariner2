/**
 * @name MemStorageService.h
 * @author jj
 * @brief The engine's storage system. This is used to store aribitary peices of
 * data into engine memory. 
 */

#include "Services/m_MemStorageService.h"

namespace Mariner {
    
    namespace Services {
        
            m_MemStorageService* m_MemStorageService::New() {

                static m_MemStorageService* Instance = new m_MemStorageService();
                Instance->Name = "MemStorageService";
                Instance->ClassName = "m_MemStorageService";
                return Instance;
                
            }

    } // namespace Services
    
} // namespace Mariner
