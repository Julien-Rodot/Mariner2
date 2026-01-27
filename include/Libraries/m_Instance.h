#pragma once

/**
 * @param name MString.cpp
 * @author jj
 * @brief The instance lib. For objects, NOT SERVICES!
 */

namespace Mariner {

    namespace Libraries {

        class m_InstanceLib {

            public:

                static m_InstanceLib* OpenLibrary();

                template<typename T>
                T* New() {

                    return T::New();

                }

                template<typename T>
                T* FromExisting() {

                    return T::New();

                }

            protected:

            private:

                m_InstanceLib() = default;
                virtual ~m_InstanceLib() = default;

        };
        
    } // namespace Libraries
    

} // namespace Mariner
