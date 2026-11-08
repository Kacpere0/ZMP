#include <iostream>
#include "Interp4Pause.hh"

using std::cout;
using std::endl;

extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
}

AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Pause();
}

Interp4Pause::Interp4Pause()
{}

void Interp4Pause::PrintSyntax() const
{
  cout << "   Pause  czas_pauzy_ms" << endl;
}

const char* Interp4Pause::GetCmdName() const {
  return "Pause";
}

void Interp4Pause::PrintCmd() const {
  cout << "   " << GetCmdName() <<  "  " << Pause_time_ms << endl;
}

bool Interp4Pause::ReadParams(std::istream &rStrm_CmdList) {
  rStrm_CmdList >> Pause_time_ms;

  if (rStrm_CmdList.fail()) {
    return false;
  }
  return true;
}

// tymczasowa wesja
bool Interp4Pause::ExecCmd(Scene &Scn) {
  PrintCmd();
  
  return true;
}