#include <iostream>
#include "Interp4Rotate.hh"

using std::cout;
using std::endl;

extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
}

AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Rotate();
}

Interp4Rotate::Interp4Rotate()
{}

void Interp4Rotate::PrintSyntax() const
{
  cout << "   Rotate  nazwa_obiektu  nazwa_osi  szybkość_katowa  kat_obrotu" << endl;
}

const char* Interp4Rotate::GetCmdName() const {
  return "Rotate";
}

void Interp4Rotate::PrintCmd() const {
  cout << "   " << GetCmdName() <<  "  " << ObjName << "  " << AxisName << "  " << AngVelocity << "  " << RotationAng << endl;
}

bool Interp4Rotate::ReadParams(std::istream &rStrm_CmdList) {
  rStrm_CmdList >> ObjName >> AxisName >> AngVelocity >> RotationAng;

  if (rStrm_CmdList.fail()) {
    return false;
  }
  return true;
}

// tymczasowa wesja
bool Interp4Rotate::ExecCmd(Scene &Scn) {
  PrintCmd();
  
  return true;
}