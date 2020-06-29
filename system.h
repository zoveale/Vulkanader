#ifndef SYSTEM_H
#define SYSTEM_H

#include "renderApi.h"

class System {
public:
  void InitSystems();
  void MainLoop();
  void Cleanup();
private:
  GLFWwindow* window;
  RenderVk renderVk;
};

#endif // !SYSTEM_H


