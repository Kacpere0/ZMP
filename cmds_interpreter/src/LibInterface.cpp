#include <iostream>
#include "LibInterface.hh"

using namespace std;

LibInterface::~LibInterface() {
    if (LibHandler) { dlclose(LibHandler); }
}

bool LibInterface::Init(std::string &LibName) {
    LibHandler = dlopen(LibName.c_str(), RTLD_LAZY);
    if (!LibHandler) {
        cerr << "!!! Brak wtyczki: " << LibName << endl;
        return false; 
    }

    void *pFun = dlsym(LibHandler, "CreateCmdInterp");
    if (!pFun) {
        cerr << "!!! Nie znaleziono funkcji CreateCmdInterp w " << LibName << endl;
        dlclose(LibHandler);
        LibHandler = nullptr;
        return false;
    }

    pCreateInterp = reinterpret_cast<AbstractInterp4Command* (*)(void)>(pFun);

    AbstractInterp4Command *tmpCmd = pCreateInterp();
    if (!tmpCmd) {
        cerr << "!!! Błąd tworzenia instancji interpretera z " << LibName << endl;
        return false;
    }

    CmdName = tmpCmd->GetCmdName();
    delete tmpCmd;

    cout << ":) Załadowano wtyczkę \"" << LibName 
         << "\" dla polecenia \"" << CmdName << "\"." << endl;
    
    return true;
}