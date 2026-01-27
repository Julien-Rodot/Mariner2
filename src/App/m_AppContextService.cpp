/**
 * @name m_Application.h
 * @author jj
 * @brief AppContextService is responsible for the management of the entire
 * engine, including things like CDC (Cross DataModel Communication), enforcing
 * FastFlags to the engine, making sure DM's dont fuck with eachother when they 
 * arent supposed to be, loading Extensions, etc.
 */

#include "App/m_AppContextService.hpp"

m_AppContextService::m_AppContextService() {

   this->LoadFastFlags();
   //this->LoadExtension(NULL);
   this->LoadEngine();

}

bool m_AppContextService::LoadExtension(const char* DylibPath) {

    void* Dylib = dlopen(DylibPath, RTLD_LAZY);

    if (DylibPath == NULL) {

        std::puts("Extension failed to load!");
        return false;

    }

    void (*m_Extension_Start)(const char * str) = (void(*)(const char*)) dlsym(Dylib, "m_Extension_Start");
    if(m_Extension_Start == NULL) {

        std::printf("Extension failed to load at path: %s\n", DylibPath);        

    }

    return true;

};

bool m_AppContextService::LoadFastFlags() {

    return true;

}

bool m_AppContextService::LoadEngine() {

    m_EngineContextService* EngineContextService = new m_EngineContextService();
    return true;

}