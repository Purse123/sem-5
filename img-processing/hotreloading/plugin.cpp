#include "plugin.h"
#include <dlfcn.h>
#include <iostream>
#include <string>

// Plugin {void* handle; display_t display; int version;}

static std::string makeName(int version) {
  return "./libhello_" + std::to_string(version) + ".so";
}

bool loadPlugin(Plugin& p) {
  std::string name = makeName(p.version);

  // open dynamic library open
  p.handle = dlopen(name.c_str(), RTLD_NOW);
  if(!p.handle) {
    std::cerr << "[ERROR] dlopen: " << dlerror() << std::endl;
    return false;
  }

  // function handler with function pointer
  p.display = (display_t)dlsym(p.handle, "display");
  if(!p.display) {
    std::cerr << "[ERROR] dlsym: " << dlerror() << std::endl;
    return false;
  }

  std::cout << "[INFO] loaded " << name << std::endl;
  return true;
}

void unloadPlugin(Plugin& p) {
  if (p.handle) {
    dlclose(p.handle);
    p.handle = nullptr;
    p.display = nullptr;
  }
}

bool reloadPlugin(Plugin& p) {
  unloadPlugin(p);
  p.version++;
  return loadPlugin(p);
}
