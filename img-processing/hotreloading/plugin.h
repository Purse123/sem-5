#ifndef PLUGIN_H
#define PLUGIN_H

#include "hello.h"
#include <iostream>

struct Plugin {
  void* handle;
  display_t display;
  int version;
};

static std::string makeName(int version);

bool loadPlugin(Plugin& p);
bool reloadPlugin(Plugin& p);
void unloadPlugin(Plugin& p);

#endif // PLUGIN_H
