#ifndef SET4LIBINTERFACES_HH
#define SET4LIBINTERFACES_HH

#include <map>
#include <memory>
#include "LibInterface.hh"

typedef std::map<std::string, std::shared_ptr<LibInterface>>::iterator map_itLib;

class Set4LibInterfaces : public std::map<std::string, std::shared_ptr<LibInterface>> {
public:
    bool AddPlugin(const std::string &LibName);
    std::shared_ptr<LibInterface> FindPlugin(const std::string &CmdName);
};

#endif