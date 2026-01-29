#pragma once

/**
 * @param name MString.cpp
 * @author jj
 * @brief The instance lib. For objects, NOT SERVICES!
 */

namespace Mariner {

    namespace Libraries {

        class m_Instance {

            public:

                template<typename T>
                static T* New() {

                    return T::New();

                }

                template<typename T>
                static T* FromExisting() {

                    return T::New();

                }

            protected:

            private:

                m_Instance() = default;
                virtual ~m_Instance() = default;

        };
        
    } // namespace Libraries
    

} // namespace Mariner
