/**
 * @name m_Job.h
 * @author jj
 * @brief The basic Job.
 */

#include "Objects/m_Job.h"
#include "Objects/m_Thread.h"

namespace Mariner {

    namespace Objects {

        m_Job* m_Job::New() {

            m_Job* Instance = new m_Job();
            Instance->Name = "Job";
            Instance->ClassName = "m_Job";
            return Instance;

        }
        
    } // namespace Objects
    
} // namespace Mariner


