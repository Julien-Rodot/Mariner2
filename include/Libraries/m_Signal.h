#pragma once

/**
 * @name Signal.h
 * @author jj
 * @brief The signal object, you can connnect to it and when it fires all
 * functions connected to it will run.
 */

#include <functional>
#include "Libraries/m_Array.h"
#include "Libraries/m_SignalConnection.h"

namespace Mariner {
    
    namespace Libraries {
        
        template<typename... Args>
        class m_Signal {

            public:

                static m_Signal* New();
                
                m_SignalConnection<Args...>** Connect(std::function<void(Args...)> FunctionToConnect);
                void Fire(Args... args);

                m_Signal() = default;
                virtual ~m_Signal() = default;

            protected:

            private:

                m_Array<m_SignalConnection*> ConnectedSignals = {};

        };

    } // namespace Libraries
    
} // namespace Mariner
