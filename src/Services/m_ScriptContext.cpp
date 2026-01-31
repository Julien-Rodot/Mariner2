/**
 * @name ScriptContext.h
 * @author jj
 * @brief Everything related to scripts is handled here.
 */

#include "cling/Interpreter/Value.h"
#include <memory>

#include "Services/m_ScriptContext.h"
#include "Objects/m_DataModel.h"

 namespace Mariner {
    
    namespace Services {
        
        m_ScriptContext* m_ScriptContext::New() {

            static m_ScriptContext* Instance = new m_ScriptContext();
            Instance->Name = "ScriptContext";
            Instance->ClassName = "m_ScriptContext";
            return Instance;

        };

        bool m_ScriptContext::ExecuteScript() {

            static Mariner::Objects::m_DataModel* Model = Mariner::Objects::m_DataModel::New();

            auto Descendants = Model->GetDescendants();

            for (Mariner::Objects::m_Object* Obj : Descendants) {

                auto* Script = dynamic_cast<Mariner::Objects::m_BaseScript*>(Obj);
                if (!Script) continue;

                std::unique_ptr<cling::Interpreter>* InterpreterPtr =
                    ScriptsToExecute.Get(Script);

                if (!InterpreterPtr) {

                    int argc = 1;
                    const char* argv[] = { "mariner" };

                    auto NewInterpreter = std::make_unique<cling::Interpreter>(argc, argv, "/Users/28rj102230/Developer/Mariner/extern/cling");
                    ScriptsToExecute.Add(Script, std::move(NewInterpreter));

                    InterpreterPtr = ScriptsToExecute.Get(Script);
                }

                if (Script->IsLoaded) continue;

                cling::Interpreter& Interpreter = **InterpreterPtr;

                cling::Value Result;
                auto Status = Interpreter.process(Script->Source.ToCString(), &Result);

                if (Status != cling::Interpreter::kSuccess) {

                    OnScriptErrored.Fire(

                        Mariner::Libraries::m_String("Script execution failed")

                    );

                    return false;
                }

                Script->IsLoaded = true;
            }

            return true;
        }

    } // namespace Services
    
 } // namespace Mariner
 