#include "Set4LibInterfaces.hh"

bool Set4LibInterfaces::AddPlugin(const std::string &LibName) {
    std::string pluginName = LibName;
    
    auto pLib = std::make_shared<LibInterface>();
    if (!pLib->Init(pluginName)) {
        return false;
    }

    (*this)[pLib->GetCmdName()] = pLib;
    return true;
}

std::shared_ptr<LibInterface> Set4LibInterfaces::FindPlugin(const std::string &CmdName) {
    auto it = this->find(CmdName);

    if (it == this->end()) {
        return nullptr;
    }

    return it->second;
}