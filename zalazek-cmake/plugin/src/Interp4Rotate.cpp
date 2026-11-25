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

  if (AngVelocity == 0 || RotationAng < 0) {
    return false;
  }

  int axisIdx;
  if (AxisName == "OX") {
    axisIdx = 0;
  } else if (AxisName == "OY") {
    axisIdx = 1;
  } else if (AxisName == "OZ") {
    axisIdx = 2;
  } else {
    return false;
  }

  double totalTime_s = RotationAng / std::abs(AngVelocity);

  int steps = 10;
  double stepAng = (AngVelocity >= 0 ? 1.0 : -1.0) * (RotationAng / steps);

  int stepTime_ms = static_cast<int>((totalTime_s * 1000.0) / steps);

  for (int i = 0; i < steps; ++i) {
    std::ostringstream oss;

    {
      std::lock_guard<std::mutex> lock(Object->UseGuard());

      Object->UseRotAng_deg()[axisIdx] += stepAng;
      oss << Object->GetName() << "  Pos: " << Object->GetPos_m() << "  Rot: " << Object->GetRotAng_deg() << "\n";
    }

    Channel.Print(oss.str());
    std::this_thread::sleep_for(std::chrono::milliseconds(stepTime_ms));
  }
  
  return true;
}