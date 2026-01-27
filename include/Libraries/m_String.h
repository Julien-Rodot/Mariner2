#pragma once

/**
 * @param name MString.cpp
 * @author jj
 * @brief The string library
 */

#include <string>

namespace Mariner
{

    namespace Libraries
    {

        class m_String {

            public:

                m_String() = default;
                m_String(const char* String);
                
                static m_String* OpenLibrary();

                static const char* ToCString(const m_String& String);
                const char* ToCString();

                virtual ~m_String() = default;

                bool operator==(m_String String2) {

                    return strcmp(this->InternalString.c_str(), String2.InternalString.c_str()) == 0;

                }

            private:

                std::string InternalString;

        };
        
    } // namespace Libraries
    
} // namespace Mariner

