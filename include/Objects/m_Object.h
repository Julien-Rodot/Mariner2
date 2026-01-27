#pragma once

/**
 * @name Object.h
 * @author jj
 * @brief The basic object in Mariner. 
 */

#include "Libraries/m_String.h"
#include "Libraries/m_Array.h"

namespace Mariner {
    
    namespace Objects {

        class m_Object {

            public:

                static m_Object* New();
                Libraries::m_String Name;
                Libraries::m_String  ClassName;
                m_Object* Parent;

                void SetParent(m_Object* ObjectToParentTo);

            protected:

                m_Object() = default;
                virtual ~m_Object() = default;

            private:

                Libraries::m_Array<m_Object*> Children;


        };
        
    } // namespace Objects
    

} // namespace Mariner

