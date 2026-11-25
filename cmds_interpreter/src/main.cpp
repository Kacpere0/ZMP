#include "ProgramInterpreter.hh"
#include <thread>

int main() {
  g3d::Vector::SetDisplayPrecision(4);
  ProgramInterpreter program;
  
  std::thread t1(&ProgramInterpreter::ExecProgram, &program, "polecenia1.txt");
  std::thread t2(&ProgramInterpreter::ExecProgram, &program, "polecenia2.txt");

  t1.join();
  t2.join();

  return 0;
}