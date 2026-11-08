#include "Scene.hh"

bool Scene::AddGeomObj(const std::string &ObjName) {
    std::string objectName = ObjName;

    std::shared_ptr<GeomObject> pGeom = std::make_shared<GeomObject>();
    
    pGeom->SetName(objectName);

    (*this)[pGeom->GetName()] = pGeom;

    return true;
}

std::shared_ptr<GeomObject> Scene::FindGeomObj(const std::string &ObjName) {
    map_it it = this->find(ObjName);

    if (it == this->end()) {
        return nullptr;
    }

    return it->second;
}