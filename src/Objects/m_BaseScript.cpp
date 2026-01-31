/**
 * @name BaseScript.h
 * @author jj
 * @brief The base script.
 */

#include "Objects/m_BaseScript.h"

namespace Mariner {
    
    namespace Objects {
        
        m_BaseScript* m_BaseScript::New() {

            m_BaseScript* Instance = new m_BaseScript();
            Instance->Name = "BaseScript";
            Instance->ClassName = "m_BaseScript";
            Instance->IsLoaded = false;
            return Instance;

        };

        void m_BaseScript::Reload() {

            this->IsLoaded = false;

        }

    } // namespace Objects
    
} // namespace Mariner
