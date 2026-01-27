/**
 * @name Signal.h
 * @author jj
 * @brief The signal object, you can connnect to it and when it fires all
 * functions connected to it will run.
 */

#include "Libraries/m_SignalConnection.h"

namespace Mariner {
    
    namespace Libraries {
        
        m_SignalConnection* m_SignalConnection::New() {

            static m_SignalConnection* Instance = new m_SignalConnection();
            return Instance;

        };

    } // namespace Libraries
    
} // namespace Mariner
