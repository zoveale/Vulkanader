#include "system.h"

int main() {
  System core;

  core.InitSystems();
  core.MainLoop();
  core.Cleanup();


  return 0;
}