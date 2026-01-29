#pragma once

/**
 * @name Vector3D.h
 * @author jj
 * @brief A type that describes the position, rotation and size of an object in
 * the world.
 */

namespace Mariner {
    
    namespace Libraries {

        class m_Vector3DLib {

            public:

                static m_Vector3DLib* OpenLibrary();

                float x = 0;
                float y = 0;
                float z = 0;

                m_Vector3DLib New(float x, float y, float z) {

                    this->x = x;
                    this->y = y;
                    this->z = z;
                    return *this;

                }

                void operator=(m_Vector3DLib OtherVector) {

                    this->x = OtherVector.x;
                    this->y = OtherVector.y;
                    this->z = OtherVector.z;

                }

                m_Vector3DLib() = default;
                virtual ~m_Vector3DLib() = default;

            protected:

            private:

        };
        
    } // namespace Libraries
    
} // namespace Mariner
