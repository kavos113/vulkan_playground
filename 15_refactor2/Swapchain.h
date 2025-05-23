#ifndef REFACTOR2_SWAPCHAIN_H
#define REFACTOR2_SWAPCHAIN_H

#define GLFW_INCLUDE_VULKAN
#include <vector>
#include <GLFW/glfw3.h>

#include "QueueFamilyIndices.h"


class Swapchain
{
public:

    struct SwapChainSupportDetails
    {
        VkSurfaceCapabilitiesKHR capabilities{};
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };

    static SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device, VkSurfaceKHR surface);

    void create(
        VkPhysicalDevice physicalDevice,
        VkDevice device,
        VkSurfaceKHR surface,
        QueueFamilyIndices indices
    );
    void createFramebuffers(VkDevice device, VkRenderPass renderPass);
    void cleanup(VkDevice device);
    void cleanupSemaphore(VkDevice device);
    void recreate(
        VkPhysicalDevice physicalDevice,
        VkDevice device,
        VkSurfaceKHR surface,
        VkRenderPass renderPass,
        QueueFamilyIndices indices
    );

    uint32_t currentImage(VkDevice device, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkRenderPass renderPass, uint32_t currentFrame);

    VkFormat format() const { return swapChainImageFormat; }
    VkExtent2D extent() const { return swapChainExtent; }
    VkFramebuffer framebuffer(uint32_t index) const { return swapChainFramebuffers[index]; }
    VkSemaphore imageAvailableSemaphore(uint32_t index) const { return imageAvailableSemaphores[index]; }
    VkSwapchainKHR handle() const { return swapChain; }

private:

    void createSwapChain(
        VkPhysicalDevice physicalDevice,
        VkDevice device,
        VkSurfaceKHR surface,
        QueueFamilyIndices indices
    );
    void createImageView(VkDevice device);
    void createSemaphore(VkDevice device, uint32_t size);

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);

    GLFWwindow* window = nullptr;

    VkSwapchainKHR swapChain = VK_NULL_HANDLE;
    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    VkFormat swapChainImageFormat = VK_FORMAT_UNDEFINED;
    VkExtent2D swapChainExtent = {};
    std::vector<VkFramebuffer> swapChainFramebuffers;

    std::vector<VkSemaphore> imageAvailableSemaphores;
};



#endif //REFACTOR2_SWAPCHAIN_H
