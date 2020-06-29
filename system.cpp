#include "system.h"

void System::InitSystems() {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  window = glfwCreateWindow(WindowInfo::WIDTH,
    WindowInfo::HEIGHT,
    WindowInfo::TITLE,
    nullptr,
    nullptr);

  renderVk.InitVk();
}

void System::MainLoop() {


  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();


  }
}

void System::Cleanup() {
  renderVk.Cleanup();
  glfwDestroyWindow(window);
  glfwTerminate();
}
