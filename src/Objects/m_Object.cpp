/**
 * @name Object.cpp
 * @author jj
 * @brief The basic object in Mariner. 
 */

#include "Objects/m_Object.h"

namespace Mariner {

    namespace Objects {

        m_Object* m_Object::New() {

            m_Object* Instance = new m_Object();
            Instance->Name = "Object";
            Instance->ClassName = "m_Object";
            return Instance;

        }

        void m_Object::SetParent(m_Object* ObjectToParent) {

            if (Parent) {

                Mariner::Libraries::m_Array<m_Object*>::Remove(Parent->Children, this);

            }

            if (ObjectToParent) {

                Mariner::Libraries::m_Array<m_Object*>::Add(ObjectToParent->Children, this);
                
            }

            Parent = ObjectToParent;
        }

        
    } // namespace Objects
    
} // namespace Mariner
