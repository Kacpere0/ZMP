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