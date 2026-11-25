#include "GeomObject.hh"

void GeomObject::SetName(const std::string &name) { Name = name; }

g3d::Vector &GeomObject::UsePos_m() { return this->Pos_m; }
g3d::Vector &GeomObject::UseRotAng_deg() { return this->RotAng_deg; }

const std::string &GeomObject::GetName() const { return Name; }
const g3d::Vector &GeomObject::GetPos_m() const { return Pos_m; }
const g3d::Vector &GeomObject::GetRotAng_deg() const { return RotAng_deg; }