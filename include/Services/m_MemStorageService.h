#pragma once

#include <any>
#include "Objects/m_Object.h"

namespace Mariner {

    namespace Services {

        class m_MemStorageService : public Objects::m_Object {

            public:

                static m_MemStorageService* New();

                template<typename T>
                void Store(Libraries::m_String Key, T Value) {

                    for (auto& E : Storage) {
                        if (E.Key == Key) {
                            E.Value = std::any(std::move(Value));
                            return;
                        }
                    }

                    Libraries::m_Array<Entry>::Add(
                        Storage,
                        Entry{ Key, std::any(std::move(Value)) }
                    );
                }

                template<typename T>
                T Load(Libraries::m_String Key) {

                    for (auto& E : Storage) {
                        if (E.Key == Key) {
                            return std::any_cast<T>(E.Value);
                        }
                    }

                    throw std::bad_any_cast();
                }

            private:

                struct Entry {
                    Libraries::m_String Key;
                    std::any Value;
                };

                m_MemStorageService() = default;
                virtual ~m_MemStorageService() = default;

                Libraries::m_Array<Entry> Storage;
        };

    } // namespace Services

} // namespace Mariner
