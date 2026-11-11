#include "ProgramInterpreter.hh"

int main() {
  ProgramInterpreter program;
  
  if(!program.ExecProgram("polecenia.txt")) {
    return 1;
  }

  return 0;
}