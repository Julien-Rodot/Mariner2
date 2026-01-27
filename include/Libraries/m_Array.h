#pragma once

/**
 * @param name MString.cpp
 * @author jj
 * @brief The array lib. Made at 1am
 */

#include <vector>
#include <string>
#include <algorithm>

namespace Mariner
{

    namespace Libraries
    {

        template<typename T>
        class m_Array {

            public:

                m_Array() = default;
                static m_Array<T>* OpenLibrary();
                
                T& operator[](size_t Index) {

                    return InternalVector[Index];

                }

                const T& operator[](size_t Index) const {

                    return InternalVector[Index];

                }

                static void Add(m_Array& Array, const T& Value) {

                    Array.InternalVector.push_back(Value);

                }

                void Add(const T& Value) {

                    this->InternalVector.push_back(Value);

                }

                static void Remove(m_Array& Array, const T& Value) {

                    Array.InternalVector.erase(std::remove(Array.InternalVector.begin(), Array.InternalVector.end(), Value), Array.InternalVector.end());
                }

                void Remove(const T& Value) {

                    this->InternalVector.erase(std::remove(this->InternalVector.begin(), this->InternalVector.end(), Value), this->InternalVector.end());

                }

                static size_t Size(m_Array& Array) {

                    return Array.InternalVector.size();

                }

                size_t Size() {

                    return this->InternalVector.size();

                }

                static void Clear(m_Array& Array) {

                    Array.InternalVector.clear();
                }

                void Clear() {

                    this->InternalVector.clear();

                }

                static bool IsEmpty(m_Array& Array) {

                    return Array.InternalVector.empty() ? true : false;

                }

                bool IsEmpty() {

                    return this->InternalVector.empty() ? true : false;                    

                }
                
                auto begin() { return InternalVector.begin(); }
                auto end() { return InternalVector.end(); }

                const auto begin() const { return InternalVector.begin(); }
                const auto end() const { return InternalVector.end(); }

            private:

                std::vector<T> InternalVector;

        };
        
    } // namespace Libraries
    
} // namespace Mariner
