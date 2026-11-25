#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include <string>
#include <dlfcn.h>
#include <AbstractInterp4Command.hh>

class LibInterface {
    void *LibHandler = nullptr;
    std::string CmdName;
    AbstractInterp4Command *(*pCreateInterp)(void) = nullptr;
public:
    ~LibInterface();

    bool Init(std::string &LibName);
    const std::string GetCmdName() const { return CmdName; } 

    AbstractInterp4Command* CreateCmd() const {
        return pCreateInterp ? pCreateInterp() : nullptr;
    }
};

#endif