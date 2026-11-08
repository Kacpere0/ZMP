#include "Set4LibInterfaces.hh"
#include "Scene.hh"

class ProgramInterpreter {
    Set4LibInterfaces LibManager;
    Scene Scn;
public:
    bool ExecProgram(const char* Prog);
};