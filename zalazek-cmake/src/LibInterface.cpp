#include "LibInterface.hh"

LibInterface::LibInterface() {
//    void *LibHandler = dlopen(PLUGIN_NAME,RTLD_LAZY);
//    AbstractInterp4Command *(*pCreateInterp)(void) = dlsym(LibHandler, "CreateCmdInterp");
// do dopracki ;P
}

LibInterface::~LibInterface() {
    if (LibHandler) { dlclose(LibHandler); }
}