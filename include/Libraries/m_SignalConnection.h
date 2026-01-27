#pragma once

/**
 * @name Object.h
 * @author jj
 * @brief The basic object in Mariner. 
 */

#include <functional>

namespace Mariner {

    namespace Libraries {

        template<typename... Args>
        class m_SignalConnection {

            public:

                static m_SignalConnection* New() {

                    static m_SignalConnection* Instance = new m_SignalConnection();
                    return Instance;

                }

                std::function<std::function<void(Args...)>> StoredFunction;

                m_SignalConnection() = default;
                virtual ~m_SignalConnection() = default;

            protected:

            private:

        };
        
    } // namespace Libraries
    
} // namespace Mariner
