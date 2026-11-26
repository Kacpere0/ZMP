#include "Interp4Move.hh"


using std::cout;
using std::endl;


extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
}




/*!
 * \brief Tworzy obiekt klasy Interp4Move.
 *
 * Tworzy obiekt klasy Interp4Move.
 * \return Zwraca wskaźnik na obiekt klasy bazowej utworzonego
 *         obiektu klas Inter4Move.
 */
AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Move();
}


/*!
 *
 */
Interp4Move::Interp4Move()
{}



/*!
 * Wyświetla składnię polecenia.
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  nazwa_obiektu  szybkosc[m/s]  dlugosc_drogi[m]" << endl;
}

const char* Interp4Move::GetCmdName() const {
  return "Move";
}

void Interp4Move::PrintCmd() const {
  cout << "   " << GetCmdName() << "  " << ObjName << "  " << Speed_mS << "  " << Distance_m << endl;
}

bool Interp4Move::ReadParams(std::istream &rStrm_CmdList) {
  rStrm_CmdList >> ObjName >> Speed_mS >> Distance_m; 
  
  if (rStrm_CmdList.fail()) {
    return false;
  }
  if (Speed_mS == 0 || Distance_m < 0) {
    return false;
  }

  return true;
}

bool Interp4Move::ExecCmd(Scene &Scn, ComChannel &Channel) {
  std::shared_ptr<GeomObject> Object = Scn.FindGeomObj(ObjName);
  if (Object == nullptr) {
    return false;
  }

  double totalTime_ms = Distance_m / std::abs(Speed_mS) * 1000.0;
  const int stepTime_ms = 100;

  int steps = std::max(1, static_cast<int>(std::round(totalTime_ms / stepTime_ms)));
  double stepDist = (Speed_mS >= 0 ? 1.0 : -1.0) * (Distance_m / steps);

  for (int i = 0; i < steps; ++i) {
    std::ostringstream oss;

    {
      std::lock_guard<std::mutex> lock(Object->UseGuard());

      double yaw_rad = Object->GetRotAng_deg()[2] * M_PI / 180.0;

      Object->UsePos_m()[0] += stepDist * std::cos(yaw_rad);
      Object->UsePos_m()[1] += stepDist * std::sin(yaw_rad);

      oss << "Move: " << Object->GetName() << "  Pos: " << Object->GetPos_m() << "  Rot: " << Object->GetRotAng_deg() << "\n";
    }

    Channel.Print(oss.str());
    std::this_thread::sleep_for(std::chrono::milliseconds(stepTime_ms));
  }

  return true;
}