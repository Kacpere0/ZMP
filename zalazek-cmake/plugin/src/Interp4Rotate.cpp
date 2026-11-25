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

bool Interp4Rotate::ExecCmd(Scene &Scn, ComChannel &Channel) {
  std::shared_ptr<GeomObject> Object = Scn.FindGeomObj(ObjName);
  if (Object == nullptr) {
    return false;
  }

  if (AngVelocity >= 0) {
    if (AxisName == "OX") {
      Object->UseRotAng_deg()[0] += RotationAng;
    } else if (AxisName == "OY") {
      Object->UseRotAng_deg()[1] += RotationAng;
    } else if (AxisName == "OZ") {
      Object->UseRotAng_deg()[2] += RotationAng;
    } else {
      return false;
    }
  } else {
    if (AxisName == "OX") {
      Object->UseRotAng_deg()[0] -= RotationAng;
    } else if (AxisName == "OY") {
      Object->UseRotAng_deg()[1] -= RotationAng;
    } else if (AxisName == "OZ") {
      Object->UseRotAng_deg()[2] -= RotationAng;
    } else {
      return false;
    }
  }
  
  return true;
}