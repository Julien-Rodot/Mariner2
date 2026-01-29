#pragma once

#include "Libraries/m_Array.h"
#include "Libraries/m_Instance.h"
#include "Libraries/m_String.h"
#include "Libraries/m_Signal.h"
#include "Libraries/m_SignalConnection.h"
#include "Libraries/m_Vector3D.h"
#include "Libraries/m_Matrix.h"
#include "Utils/m_Memory.h"
#include "Objects/m_Object.h"
#include "Objects/m_DataModel.h"
#include "Objects/m_ServiceProvider.h"
#include "Objects/m_Job.h"
#include "Objects/m_Thread.h"
#include "Objects/m_Window.h"
#include "Objects/m_Camera.h"
#include "Objects/m_BasePart.h"
#include "Services/m_TaskScheduler.h"
#include "Services/m_RunService.h"
#include "Services/m_MemStorageService.h"
#include "Services/m_MessageBusService.h"
#include "Services/m_Workspace.h"

// This exists because I am too slack to define a StartEngine function 
// or something similar along the lines of that.

// We do not recommend to use or edit these functions. Things can go to shits if you do!
namespace Mariner::Internal {

    void m_Entry();

}

struct InitalizeMariner {

    InitalizeMariner() { 

        Mariner::Internal::m_Entry();

    };
    
};

static InitalizeMariner Initialize;

inline Mariner::Objects::m_DataModel* m_Game = Mariner::Objects::m_DataModel::New();