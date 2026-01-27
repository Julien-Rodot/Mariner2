#pragma once

/**
 * @name m_Job.h
 * @author jj
 * @brief The basic Job.
 */

#include <functional>
#include "Objects/m_Object.h"
#include "Libraries/m_String.h"

namespace Mariner {
    
    namespace Objects {

        class m_Thread;
        class m_Job : public m_Object {

            public:

                static m_Job* New();

                bool Cyclic = false;
                Mariner::Libraries::m_String ThreadToExecute = "";
                std::function<void()> FunctionPointer;
            
            protected:

                m_Job() = default;
                virtual ~m_Job() = default;

            private:

        };
        
    } // namespace Objects
    
} // namespace Mariner



