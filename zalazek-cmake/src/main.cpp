#include <iostream>
#include <fstream>
#include <string>
#include "Set4LibInterfaces.hh"

using namespace std;

#define PLUGIN_MOVE "libInterp4Move.so"
#define PLUGIN_SET "libInterp4Set.so"
#define PLUGIN_PAUSE "libInterp4Pause.so"
#define PLUGIN_ROTATE "libInterp4Rotate.so"

bool ReadFromFile(const string &FileName, Set4LibInterfaces &Plugins) {
  ifstream file(FileName);
  if (!file.is_open()) {
    cerr << "!!! Nie udało się załadować pliku: " << FileName << endl;
    return false;
  }

  string cmdName;
  while (file >> cmdName) {
    shared_ptr<LibInterface> plugin = Plugins.FindPlugin(cmdName);
    if (!plugin) {
      cerr << "!!! Nie znaleziono wtyczki obsługującej polecenie: " << cmdName << endl;
      return false; 
    }

    AbstractInterp4Command *pInterp = plugin->CreateCmd();
    if (!pInterp) {
      cerr << "!!! Błąd przy tworzenu instancji interpretera polecenia: " << cmdName << endl;
      return false;
    }

    cout << endl;
    pInterp->PrintSyntax();

    delete pInterp;
  }

  return true;
}

int main() {
  Set4LibInterfaces plugins;
  if (!plugins.AddPlugin(PLUGIN_MOVE) || !plugins.AddPlugin(PLUGIN_PAUSE) ||
      !plugins.AddPlugin(PLUGIN_ROTATE) || !plugins.AddPlugin(PLUGIN_SET)) {
        cerr << "!!! Błąd przy dodawaniu pluginów" << endl;
    return 1;
  }

  if (!ReadFromFile("polecenia.txt", plugins)) {
    return 1;
  }

  return 0;
}