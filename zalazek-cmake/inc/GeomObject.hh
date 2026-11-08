#ifndef GEOMOBJECT_HH
#define GEOMOBJECT_HH

#include "g3dVector.hh"

class GeomObject {
    g3d::Vector Pos_m;
    std::string Name;
public:
    const std::string &GetName() const;
    void SetName(const std::string &name);
    const g3d::Vector &GetPos_m() const;
    g3d::Vector &UsePos_m();
};

#endif