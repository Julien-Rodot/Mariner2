/**
 * @name m_Application.h
 * @author jj
 * @brief AppContextService is responsible for the management of the entire
 * engine, including things like CDC (Cross DataModel Communication), enforcing
 * FastFlags to the engine, making sure DM's dont fuck with eachother when they 
 * arent supposed to be, loading Extensions, etc.
 */

#include <stdio.h>
#include <string>
#include <filesystem>
#include <dlfcn.h>

#include "Core/m_EngineContextService.hpp"

class m_AppContextService {

    public:

        m_AppContextService();
        
        bool LoadExtension(const char* DylibPath);
        bool LoadFastFlags();
        bool LoadEngine();

    private:

        std::string WorkingDirectory;

    
};