/**
 * @param name m_Dictionary.cpp
 * @author jj
 * @brief The dictionary lib.
 */

#include "Libraries/m_Dictionary.h"

namespace Mariner {

    namespace Libraries {

        template<typename K, typename V>
        m_Dictionary<K, V>* m_Dictionary<K, V>::OpenLibrary() {

            static m_Dictionary* Instance = new m_Dictionary();
            return Instance;

        };
        
    } // namespace Libraries
    
} // namespace Mariner
