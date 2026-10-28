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
    LibInterface();
    ~LibInterface();
};

#endif