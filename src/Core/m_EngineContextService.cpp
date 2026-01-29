/**
 * @name m_EngineContextService.cpp
 * @author jj
 * @brief AppContextService is responsible for the management of the entire
 * engine, including things like CDC (Cross DataModel Communication), enforcing
 * FastFlags to the engine, making sure DM's dont fuck with eachother when they 
 * arent supposed to be, loading Extensions, etc.
 */

#include "Core/m_EngineContextService.hpp"
#include <print>


m_EngineContextService::m_EngineContextService() {

    this->CreateSomeThingsAndSetMoreShitUp();

}

void m_EngineContextService::CreateSomeThingsAndSetMoreShitUp() {

    auto DataModel = Mariner::Objects::m_DataModel::New();
    
    auto TaskScheduler = Mariner::Services::m_TaskScheduler::New();
    TaskScheduler->SetParent(DataModel);

    auto MainThread = Mariner::Objects::m_Thread::New();
    MainThread->Name = "m_MainThread";
    MainThread->SetThread(pthread_self());
    MainThread->SetParent(TaskScheduler);

    TaskScheduler->AddThread(MainThread);

    auto MemStorageService = Mariner::Services::m_MemStorageService::New();
    MemStorageService->SetParent(DataModel);

    auto Window = Mariner::Objects::m_Window::New();
    Window->SizeX = 800;
    Window->SizeY = 600;
    Window->SetParent(DataModel);
    Window->CreateWindow();

    auto MessageBusService = Mariner::Services::m_MessageBusService::New();
    MessageBusService->SetParent(DataModel);

    auto Workspace = Mariner::Services::m_Workspace::New();
    Workspace->SetParent(DataModel);
    
    return;

}