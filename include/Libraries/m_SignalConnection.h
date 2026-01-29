#pragma once

/**
 * @name SignalConnection.h
 * @author jj
 * @brief Stores a connection to a signal.
 */

#include <functional>

namespace Mariner {

    namespace Libraries {

        template<typename... Args>
        class m_SignalConnection {

            public:

                static m_SignalConnection* New() {

                    return new m_SignalConnection();

                }

                std::function<void(Args...)> StoredFunction;

                m_SignalConnection() = default;
                virtual ~m_SignalConnection() = default;

            };

        template<>
        class m_SignalConnection<void> {

            public:

                static m_SignalConnection* New() {

                    return new m_SignalConnection();

                }

                std::function<void()> StoredFunction;

                m_SignalConnection() = default;
                virtual ~m_SignalConnection() = default;

            };

    } // namespace Libraries

} // namespace Mariner
