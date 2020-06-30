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

//c++ 17
#include <optional>
//
#include <stdexcept>
#include <string>
#include <vector>

#include "singletons.h"

class RenderVk {
public:
  void InitVk();
  void CreateInstance();

  void Cleanup();
  


private:
  VkInstance instance;
  VkDebugUtilsMessengerEXT debugMessenger;

  const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
  };
  /// <PhysicalDeviceLogicFunctions>
  void PickPhysicalDevice();
  bool IsDeviceSuitable(VkPhysicalDevice device);
  /// <QueueFamilies>
  struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    bool IsComplete();
  };
  QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
  /// </QueueFamilies>
  /// </PhysicalDeviceLogicFunctions>
  
 
  
  /// <HelperFunctions>
  void PrintExtensions();
  /// </HelperFunctions>

  /// <DebugLogic>
  void SetupDebugMessenger();
  bool CheckValidationLayerSupport();
  std::vector<const char*> GetRequiredExtensions();
  static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData);
  VkResult CreateDebugUtilsMessengerEXT(VkInstance instance,
    const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDebugUtilsMessengerEXT* pDebugMessenger);
  void DestroyDebugUtilsMessengerEXT(VkInstance instance,
    VkDebugUtilsMessengerEXT debugMessenger,
    const VkAllocationCallbacks* pAllocator);
  void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
  /// </DebugLogic>
#ifdef NDEBUG
  const bool enableValidationLayers = false;
#else
  const bool enableValidationLayers = true;
#endif
};

#endif // !RENDERAPI_H


