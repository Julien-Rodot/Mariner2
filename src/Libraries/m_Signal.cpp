/**
 * @name Signal.h
 * @author jj
 * @brief The signal object, you can connnect to it and when it fires all
 * functions connected to it will run.
 */

#include "Libraries/m_Signal.h"

namespace Mariner {
    
    namespace Libraries {
        
        m_Signal* m_Signal::New() {

            static m_Signal* Instance = new m_Signal();
            return Instance;

        };

        m_SignalConnection* m_Signal::Connect(std::function<void()> FunctionToConnect) {

            m_SignalConnection* Connection = m_SignalConnection::New();
            Connection->StoredFunction = FunctionToConnect;
            m_Array<m_SignalConnection*>::Add(this->ConnectedSignals, Connection);
            return Connection;

        };

        void m_Signal::Fire() {

            for(auto* SignalConection : this->ConnectedSignals) {

                SignalConection->StoredFunction();

            }

        }

    } // namespace Libraries
    
} // namespace Mariner
