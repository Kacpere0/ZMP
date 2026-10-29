#include "Set4LibInterfaces.hh"

typedef std::map<std::string, std::shared_ptr<LibInterface>>::iterator map_it;

bool Set4LibInterfaces::AddPlugin(const std::string &LibName) {
    std::string pluginName = LibName;
    
    std::shared_ptr<LibInterface> pLib = std::make_shared<LibInterface>();
    if (!pLib->Init(pluginName)) {
        return false;
    }

    (*this)[pLib->GetCmdName()] = pLib;
    return true;
}

std::shared_ptr<LibInterface> Set4LibInterfaces::FindPlugin(const std::string &CmdName) {
    map_it it = this->find(CmdName);

    if (it == this->end()) {
        return nullptr;
    }

    return it->second;
}