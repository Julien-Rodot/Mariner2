#pragma once

/**
 * @name Signal.h
 * @author jj
 * @brief The signal object, you can connect to it and when it fires all
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

                static m_Signal* New() {
                    return new m_Signal();
                }

                m_SignalConnection<Args...>* Connect(std::function<void(Args...)> FunctionToConnect) {

                    auto* Connection = m_SignalConnection<Args...>::New();
                    Connection->StoredFunction = FunctionToConnect;
                    ConnectedSignals.Add(Connection);

                    return Connection;
                }

                void Fire(Args... args) {

                    for (size_t i = 0; i < ConnectedSignals.Size(); ++i) {

                        auto* conn = ConnectedSignals[i];

                        if (conn && conn->StoredFunction) {

                            conn->StoredFunction(args...);

                        }

                    }

                }
                
                m_Signal() = default;
                virtual ~m_Signal() = default;

            private:

                m_Array<m_SignalConnection<Args...>*> ConnectedSignals;

        };

        // OVERLOADS!!!
        template<>
        class m_Signal<void> {

            public:

                static m_Signal* New() { return new m_Signal(); }

                m_SignalConnection<void>* Connect(std::function<void()> FunctionToConnect) {

                    auto* connection = m_SignalConnection<void>::New();
                    connection->StoredFunction = FunctionToConnect;

                    ConnectedSignals.Add(connection);
                    return connection;

                }

                void Fire() {

                    for (size_t i = 0; i < ConnectedSignals.Size(); ++i) {

                        auto* conn = ConnectedSignals[i];
                        if (conn && conn->StoredFunction) {

                            conn->StoredFunction();

                        }

                    }

                }

            private:
            
                m_Array<m_SignalConnection<void>*> ConnectedSignals;
        };

    } // namespace Libraries

} // namespace Mariner

