#include <iostream>
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
  return true;
}

bool Interp4Move::ExecCmd(Scene &Scn) {
  std::shared_ptr<GeomObject> Object = Scn.FindGeomObj(ObjName);
  
  if (Object == nullptr) {
    return false;
  }

  if (Speed_mS >= 0) {
    Object->UsePos_m()[0] += Distance_m;
  } else {
    Object->UsePos_m()[0] -= Distance_m;
  }

  cout << "   Nowa pozycja " << ObjName << ": " << Object->GetPos_m() << endl;

  return true;
}