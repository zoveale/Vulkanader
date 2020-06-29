#ifndef RENDERAPI_H
#define RENDERAPI_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

//#define NDEBUG
#include <cassert>
#include <stdio.h>

#include <vector>

#include "singletons.h"

class RenderVk {
public:
  void InitVk();
  void CreateInstance();
  void Cleanup();

private:
  VkInstance instance;
};

#endif // !RENDERAPI_H


