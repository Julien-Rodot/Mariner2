#pragma once

/**
 * @name DataModel.h
 * @author jj
 * @brief Pretty much a scene
 */

#include "m_ServiceProvider.h"

namespace Mariner {
    
    namespace Objects {

        class m_DataModel : public m_ServiceProvider {

            public:

                static m_DataModel* New();

                // NEVER FLIP THIS IN SCRIPT CODE!!!!!
                bool IsNetworked = false;

            protected:

                m_DataModel() = default;
                virtual ~m_DataModel() = default;

            private:

        };
        
    } // namespace Objects
    

} // namespace Mariner