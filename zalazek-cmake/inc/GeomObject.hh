#ifndef GEOMOBJECT_HH
#define GEOMOBJECT_HH

#include <mutex>
#include "g3dVector.hh"

class GeomObject {
    g3d::Vector Pos_m;
    g3d::Vector RotAng_deg;
    std::string Name;
    std::mutex Guard;
public:
    const std::string &GetName() const;
    void SetName(const std::string &name);
    const g3d::Vector &GetPos_m() const;
    const g3d::Vector &GetRotAng_deg() const;
    g3d::Vector &UsePos_m();
    g3d::Vector &UseRotAng_deg();
};

#endif