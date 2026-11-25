#ifndef PROGRAMINTERPRETER_HH
#define PROGRAMINTERPRETER_HH

#include "Set4LibInterfaces.hh"
#include "Scene.hh"
#include "ComChannel.hh"
#include <iostream>
#include <fstream>

using namespace std;

#define PLUGIN_MOVE "libInterp4Move.so"
#define PLUGIN_SET "libInterp4Set.so"
#define PLUGIN_PAUSE "libInterp4Pause.so"
#define PLUGIN_ROTATE "libInterp4Rotate.so"

class ProgramInterpreter {
    Set4LibInterfaces LibManager;
    ComChannel CtrlChannel;
    Scene Scn;
public:
    ProgramInterpreter();
    bool ExecProgram(const char* FileName_Prog);
};

#endif