#pragma once

/**
 * @param name m_Dictionary.h
 * @author jj
 * @brief A dictionary lib 
 */

#include <utility>
#include <algorithm>
#include <vector>

namespace Mariner {

    namespace Libraries {

        template<typename K, typename V>
        class m_Dictionary {

            public:

                m_Dictionary() = default;
                static m_Dictionary<K,V>* OpenLibrary();

                void Add(const K& key, const V& value) {

                    InternalVector.push_back(std::make_pair(key, value));
                }

                static void Add(m_Dictionary& dict, const K& key, const V& value) {

                    dict.InternalVector.push_back(std::make_pair(key, value));

                }

                void Add(const K& key, V&& value) {

                    InternalVector.push_back(std::make_pair(key, std::forward<V>(value)));

                }


                static void Add(m_Dictionary& dict, const K& key, V&& value) {

                    dict.InternalVector.push_back(std::make_pair(key, std::forward<V>(value)));

                }

                void Remove(const K& key) {

                    InternalVector.erase(

                        std::remove_if(InternalVector.begin(), InternalVector.end(),

                            [&key](const std::pair<K,V>& kv){ return kv.first == key; }),

                        InternalVector.end()

                    );

                }

                static void Remove(m_Dictionary& dict, const K& key) {

                    dict.InternalVector.erase(

                        std::remove_if(dict.InternalVector.begin(), dict.InternalVector.end(),

                            [&key](const std::pair<K,V>& kv){ return kv.first == key; }),

                        dict.InternalVector.end()

                    );

                }

                V* Get(const K& key) {

                    for (auto& kv : InternalVector) {

                        if (kv.first == key) return &kv.second;

                    }

                    return nullptr;
                }

                const V* Get(const K& key) const {

                    for (const auto& kv : InternalVector) {

                        if (kv.first == key) return &kv.second;

                    }

                    return nullptr;
                    
                }

                bool Contains(const K& key) const {

                    return std::any_of(InternalVector.begin(), InternalVector.end(), [&key](const std::pair<K,V>& kv){ return kv.first == key; });
                }

                void Clear() {

                    InternalVector.clear(); 
                    
                }

                static void Clear(m_Dictionary& dict) {

                    dict.InternalVector.clear();

                }

                size_t Size() const { return InternalVector.size(); }
                static size_t Size(m_Dictionary& dict) { return dict.InternalVector.size(); }

                auto begin() { return InternalVector.begin(); }
                auto end() { return InternalVector.end(); }

                const auto begin() const { return InternalVector.begin(); }
                const auto end() const { return InternalVector.end(); }

            private:

                std::vector<std::pair<K,V>> InternalVector;
        };

    } // namespace Libraries
    
} // namespace Mariner
