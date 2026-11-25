#ifndef SCENE_HH
#define SCENE_HH

#include "GeomObject.hh"
#include <map>
#include <memory>

typedef std::map<std::string, std::shared_ptr<GeomObject>>::iterator map_itGeom;

class Scene : public std::map<std::string, std::shared_ptr<GeomObject>> {
public:
    bool AddGeomObj(const std::string &ObjName);
    std::shared_ptr<GeomObject> FindGeomObj(const std::string &ObjName);
};

#endif