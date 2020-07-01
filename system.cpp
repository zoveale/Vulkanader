#include "system.h"

void System::InitSystems() {

  renderVk.InitVk();
}

void System::MainLoop() {


  while (!glfwWindowShouldClose(renderVk.window)) {
    glfwPollEvents();

  }
}

void System::Cleanup() {
  renderVk.Cleanup();
  glfwDestroyWindow(renderVk.window);
  glfwTerminate();
}
