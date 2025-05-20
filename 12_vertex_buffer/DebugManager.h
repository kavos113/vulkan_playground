#ifndef REFACTOR_DEBUGMANAGER_H
#define REFACTOR_DEBUGMANAGER_H

#include <vector>
#include <vulkan/vulkan.h>

class DebugManager
{
public:
    void setup(VkInstance instance);
    void cleanup(VkInstance instance);
    void addDebugSupportToInstance(VkInstanceCreateInfo &createInfo, VkDebugUtilsMessengerCreateInfoEXT &debugCreateInfo);
    void addDebugSupportToDevice(VkDeviceCreateInfo &createInfo);
private:
    bool checkValidationLayerSupport();
    static void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);

    VkDebugUtilsMessengerEXT debugMessenger = VK_NULL_HANDLE;

    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation",
    };
};



#endif //REFACTOR_DEBUGMANAGER_H
