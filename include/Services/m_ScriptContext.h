#pragma once

/**
 * @name ScriptContext.h
 * @author jj
 * @brief Everything related to scripts is handled here.
 */


#include "cling/Interpreter/Interpreter.h"

#include "Objects/m_Object.h"
#include "Objects/m_BaseScript.h"
#include "Libraries/m_Signal.h"
#include "Libraries/m_String.h"
#include "Libraries/m_Dictionary.h"

namespace Mariner {

    namespace Services {
        
        class m_ScriptContext : public Mariner::Objects::m_Object {

            public:

                static m_ScriptContext* New();

                bool ExecuteScript();
                Mariner::Libraries::m_Signal<Mariner::Libraries::m_String> OnScriptErrored = *Mariner::Libraries::m_Signal<Mariner::Libraries::m_String>::New();

            protected:

                m_ScriptContext() = default;
                virtual ~m_ScriptContext() = default;

            private:

                Mariner::Libraries::m_Dictionary<Mariner::Objects::m_BaseScript*, std::unique_ptr<cling::Interpreter>> ScriptsToExecute = {};

        };

    } // namespace Services
    
} // namespace Mariner
