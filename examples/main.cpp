#include "Mariner/Mariner.h"
#include <print>

using namespace Mariner;
using namespace Mariner::Utils;
using namespace Mariner::Objects;   
using namespace Mariner::Internal;
using namespace Mariner::Libraries;
using namespace Mariner::Services;

int main() {

    m_Workspace* Workspace = m_Game->GetService<m_Workspace>();
    auto RunService = m_Game->GetService<m_RunService>();
    auto MessageBusService = m_Game->GetService<m_MessageBusService>();

    auto MyPart = m_Instance->New<m_BasePart>();
    MyPart->Position = m_Vector3D->New(20,20,20);
    
    auto Camera = Workspace->CurrrentCamera;
    Camera->CameraSubject = MyPart;

    MessageBusService->OnIncommingMessage.Connect([](m_String Message){

        printf("%s\n", Message.ToCString());

    });

    RunService->Run();

}
