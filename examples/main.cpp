#include "Mariner/Mariner.h"
#include <print>
#include <iostream>

using namespace Mariner;
using namespace Mariner::Utils;
using namespace Mariner::Objects;   
using namespace Mariner::Internal;
using namespace Mariner::Libraries;
using namespace Mariner::Services;

int main() {

    auto* Workspace = m_Game->GetService<m_Workspace>();
    auto RunService = m_Game->GetService<m_RunService>();
    auto ScriptContext = m_Game->GetService<m_ScriptContext>();
    auto MessageBusService = m_Game->GetService<m_MessageBusService>();

    auto MyPart = m_Instance::New<m_BasePart>();
    MyPart->Position = m_Vector3D::New(20,20,20);

    m_Matrix<double> MyMatrix = {

        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},

    };

    m_Matrix<double> MyMatrix2 = {

        {3, 2, 7},
        {4, 7, 6},
        {7, 2, 1},

    };

    m_Matrix<double> Multiplied1 = MyMatrix * MyMatrix2;
    Multiplied1.Print();

    m_Matrix<double> Multiplied2 = MyMatrix2 * MyMatrix;
    Multiplied2.Print();
    
    //Camera->CameraSubject = MyPart;

    MessageBusService->OnIncommingMessage.Connect([](m_String Message){

        printf("%s\n", Message.ToCString());

    });

    auto MyScript = m_Instance::New<m_BaseScript>();
    MyScript->Source = "int x = 1;";
    MyScript->SetParent(m_Game);

    ScriptContext->ExecuteScript();

    RunService->Run();

}
