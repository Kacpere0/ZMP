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

bool Interp4Set::ExecCmd(Scene &Scn, ComChannel &Channel) {
  std::shared_ptr<GeomObject> Object = Scn.FindGeomObj(ObjName);
  std::ostringstream oss;

  if (Object == nullptr) {
    return false;
  }
  {
    std::lock_guard<std::mutex> lock(Object->UseGuard());

    Object->UsePos_m() = {xcord, ycord, zcord};
    Object->UseRotAng_deg() = {OXangl, OYangl, OZangl};

    oss << "Set: " << Object->GetName() << "  Pos: " << Object->GetPos_m() << "  Rot: " << Object->GetRotAng_deg() << "\n";
  }

  Channel.Print(oss.str());

  return true;
}