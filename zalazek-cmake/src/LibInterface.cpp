#include <string>
#include <dlfcn.h>
#include <AbstractInterp4Command.hh>

class LibInterface {
    void *LibHandler;
    std::string CmdName;
    AbstractInterp4Command *(*pCreateInterp)(void);
public:
    LibInterface();
};

LibInterface::LibInterface() {
    
}