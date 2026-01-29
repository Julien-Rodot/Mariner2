#pragma once

/**
 * @name Vector3D.h
 * @author jj
 * @brief A type that describes the position, rotation and size of an object in
 * the world.
 */

namespace Mariner {
    
    namespace Libraries {

        class m_Vector3D {

            public:

                static m_Vector3D New(float x, float y, float z);

                float x = 0;
                float y = 0;
                float z = 0;

                void operator=(m_Vector3D OtherVector) {

                    this->x = OtherVector.x;
                    this->y = OtherVector.y;
                    this->z = OtherVector.z;

                }

                m_Vector3D() = default;
                virtual ~m_Vector3D() = default;

            protected:

            private:

        };
        
    } // namespace Libraries
    
} // namespace Mariner
