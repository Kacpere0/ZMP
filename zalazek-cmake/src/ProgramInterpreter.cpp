#include "ProgramInterpreter.hh"

ProgramInterpreter::ProgramInterpreter() {
    if (!LibManager.AddPlugin(PLUGIN_MOVE) || !LibManager.AddPlugin(PLUGIN_SET) ||
        !LibManager.AddPlugin(PLUGIN_PAUSE) || !LibManager.AddPlugin(PLUGIN_ROTATE)) {
        cerr << "!!! Błąd przy dodawaniu pluginów" << endl;
        exit(EXIT_FAILURE);
    }

    if (!Scn.AddGeomObj("Obj_A") || !Scn.AddGeomObj("Obj_B")) {
        cerr << "!!! Błąd przy dodawaniu obiektów" << endl;
        exit(EXIT_FAILURE);
    }
}

bool ProgramInterpreter::ExecProgram(const char* FileName_Prog) {
    ifstream file(FileName_Prog);
    if (!file.is_open()) {
        cerr << "!!! Nie udało się załadować pliku: " << FileName_Prog << endl;
        return false;
    }

    string cmdName;
    while(file >> cmdName) {
        shared_ptr<LibInterface> plugin = this->LibManager.FindPlugin(cmdName);
        if (!plugin) {
            cerr << "!!! Nie znaleziono wtyczki obsługującej polecenie: " << cmdName << endl;
            return false; 
        }

        AbstractInterp4Command *pInterp = plugin->CreateCmd();
        if (!pInterp) {
            cerr << "!!! Błąd przy tworzeniu instancji interpretera polecenia: " << cmdName << endl;
            return false;
        }
        
        if (!pInterp->ReadParams(file)) {
            cerr << "!!! Błąd wczytywania parametrów dla polecenia: " << cmdName << endl;
            delete pInterp;
            return false;
        }

        pInterp->PrintCmd();

        if(!pInterp->ExecCmd(this->Scn)) {
            cerr << "!!! Błąd wykonywania polecenia dla: " << cmdName << endl;
            delete pInterp;
            return false;
        }
        delete pInterp;
    }
    return true;
}