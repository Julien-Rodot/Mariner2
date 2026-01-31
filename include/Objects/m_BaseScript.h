#pragma once

/**
 * @name BaseScript.h
 * @author jj
 * @brief The base script.
 */

#include "Objects/m_Object.h"
#include "Libraries/m_Signal.h"
#include "Libraries/m_String.h"
#include "Libraries/m_Dictionary.h"

namespace Mariner {
    
    namespace Objects {

        class m_BaseScript : public Mariner::Objects::m_Object {

            public:

                static m_BaseScript* New();

                bool IsLoaded = false;
                Mariner::Libraries::m_String Source;

                void Reload();

            protected:

                m_BaseScript() = default;
                virtual ~m_BaseScript() = default;

            private:
            
        };
        
    } // namespace Objects
    
} // namespace Mariner
