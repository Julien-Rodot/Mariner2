/**
 * @name ServiceProvider.cpp
 * @author jj
 * @brief So you can do game->GetService();
 */

#include "Objects/m_ServiceProvider.h"
#include "Objects/m_DataModel.h"

namespace Mariner {
    
    namespace Objects {

        m_ServiceProvider* m_ServiceProvider::New() {

            m_ServiceProvider* Instance = new m_ServiceProvider();
            Instance->Name = "ServiceProvider";
            Instance->ClassName = "m_ServiceProvider";
            return Instance;

        };

        m_DataModel* m_ServiceProvider::GetDataModel() {

            static m_DataModel* DataModel = m_DataModel::New();
            return DataModel;

        }
    
    }; // namespace Objects
    
}; // namespace Mariner
