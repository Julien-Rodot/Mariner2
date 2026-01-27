/**
 * @param name MString.cpp
 * @author jj
 * @brief The array lib.
 */

#include "Libraries/m_Array.h"

namespace Mariner
{

    namespace Libraries
    {

        template<typename T>
        m_Array<T>* m_Array<T>::OpenLibrary() {

            static m_Array* Instance = new m_Array();
            return Instance;

        };
        
    } // namespace Libraries
    
} // namespace Mariner
