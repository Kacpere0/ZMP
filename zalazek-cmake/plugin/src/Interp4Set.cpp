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