#pragma once

/**
 * @name ServiceProvider.h
 * @author jj
 * @brief So you can do game->GetService();
 */


#include "m_Object.h"

namespace Mariner {
    
    namespace Objects {

        class m_DataModel;
        class m_ServiceProvider : public m_Object {

            public:

                static m_ServiceProvider* New();
                
                template<typename T>
                T* GetService() {

                    T* Instance = T::New();
                    Instance->SetParent(GetDataModel());
                    return Instance;

                }
                
            protected:

                m_ServiceProvider() = default;
                virtual ~m_ServiceProvider() = default;

            private:

                m_DataModel* GetDataModel();

        };
        
    } // namespace Objects
    

} // namespace Mariner

