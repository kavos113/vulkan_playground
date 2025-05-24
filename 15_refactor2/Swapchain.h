#ifndef REFACTOR2_SWAPCHAIN_H
#define REFACTOR2_SWAPCHAIN_H

#define GLFW_INCLUDE_VULKAN
#include <vector>
#include <GLFW/glfw3.h>

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
        VkSurfaceKHR surface
    );
    void createFramebuffers(VkRenderPass renderPass);
    void cleanup() const;
    void cleanupSemaphore() const;
    void recreate(VkRenderPass renderPass);

    uint32_t currentImage(VkRenderPass renderPass, uint32_t currentFrame);

    [[nodiscard]] VkFormat format() const { return swapChainImageFormat; }
    [[nodiscard]] VkExtent2D extent() const { return swapChainExtent; }
    [[nodiscard]] VkFramebuffer framebuffer(uint32_t index) const { return swapChainFramebuffers[index]; }
    [[nodiscard]] VkSemaphore imageAvailableSemaphore(uint32_t index) const { return imageAvailableSemaphores[index]; }
    [[nodiscard]] VkSwapchainKHR handle() const { return swapChain; }

private:

    void createSwapChain();
    void createImageView();
    void createSemaphore(uint32_t size);

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);
    [[nodiscard]] VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities) const;

    GLFWwindow* window = nullptr;

    VkSwapchainKHR swapChain = VK_NULL_HANDLE;
    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    VkFormat swapChainImageFormat = VK_FORMAT_UNDEFINED;
    VkExtent2D swapChainExtent = {};
    std::vector<VkFramebuffer> swapChainFramebuffers;

    std::vector<VkSemaphore> imageAvailableSemaphores;

    VkDevice m_device = VK_NULL_HANDLE;
    VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
    VkSurfaceKHR m_surface = VK_NULL_HANDLE;
};

#endif //REFACTOR2_SWAPCHAIN_H
