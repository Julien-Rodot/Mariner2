#include "Mariner/Mariner.h"
#include <print>

using namespace Mariner;
using namespace Mariner::Utils;
using namespace Mariner::Objects;   
using namespace Mariner::Internal;
using namespace Mariner::Libraries;
using namespace Mariner::Services;


int main() {

    auto RunService = m_Game->GetService<m_RunService>();

    m_Array<m_Object*> Array = {};

    Array.Add(m_Instance->New<m_Object>());
    m_Array<m_Object*>::Add(Array, m_Object::New());
    Array[1] = m_Object::New();
    std::print("{}\n", Array[1]->Name.ToCString());

    RunService->Heartbeat.Connect([]() {

        printf("%s\n", "Fired!");

    });

    RunService->Run();

}
