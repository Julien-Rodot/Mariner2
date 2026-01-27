/**
 * @param name MString.cpp
 * @author jj
 * @brief The string library
 */

#include "Libraries/m_String.h"

namespace Mariner
{

    namespace Libraries
    {

        m_String* m_String::OpenLibrary() {

            static m_String* Instance = new m_String();
            return Instance;

        };

        m_String::m_String(const char* String) {

            this->InternalString = String;

        }

        const char* m_String::ToCString(const m_String& String) {

            return String.InternalString.c_str();

        }

        const char* m_String::ToCString() {

            return this->InternalString.c_str();

        }
        
    } // namespace Libraries
    
} // namespace Mariner
