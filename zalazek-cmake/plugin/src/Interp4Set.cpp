#include <iostream>
#include "Interp4Set.hh"

using std::cout;
using std::endl;

extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
}

AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Set();
}

Interp4Set::Interp4Set()
{}

void Interp4Set::PrintSyntax() const
{
  cout << "   Set  nazwa_obiektu  wsp_x  wsp_y  wsp_z  kat_OX  kat_OY  kat_OZ" << endl;
}

const char* Interp4Set::GetCmdName() const {
  return "Set";
}

void Interp4Set::PrintCmd() const {
  cout << "   " << GetCmdName() <<  "  " << ObjName << "  " << xcord << "  " << ycord << "  "
       << zcord << "  " << OXangl << "  " << OYangl << "  " << OZangl << endl;
}

bool Interp4Set::ReadParams(std::istream &rStrm_CmdList) {
  rStrm_CmdList >> ObjName >> xcord >> ycord >> zcord >> OXangl >> OYangl >> OZangl;

  if (rStrm_CmdList.fail()) {
    return false;
  }
  return true;
}

// tymczasowa wesja
bool Interp4Set::ExecCmd(Scene &Scn) {
  PrintCmd();
  
  return true;
}