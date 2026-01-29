/**
 * @name m_Application.h
 * @author jj
 * @brief AppContextService is responsible for the management of the entire
 * engine, including things like CDC (Cross DataModel Communication), enforcing
 * FastFlags to the engine, making sure DM's dont fuck with eachother when they 
 * arent supposed to be, loading Extensions, etc.
 */

#include "Objects/m_DataModel.h"
#include "Objects/m_Thread.h"
#include "Objects/m_Window.h"

#include "Services/m_TaskScheduler.h"
#include "Services/m_MessageBusService.h"
#include "Services/m_MemStorageService.h"
#include "Services/m_Workspace.h"

class m_EngineContextService {

    public:

        m_EngineContextService();
        void CreateSomeThingsAndSetMoreShitUp();

    private:

};