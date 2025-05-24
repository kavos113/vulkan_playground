#ifndef REFACTOR2_COMMAND_H
#define REFACTOR2_COMMAND_H

#include <optional>
#include <vector>
#include <vulkan/vulkan.h>

#include "QueueFamilyIndices.h"
#include "Swapchain.h"

class Command
{
public:
    static std::vector<VkDeviceQueueCreateInfo> queueCreateInfo(VkPhysicalDevice device, VkSurfaceKHR surface);

    void create(VkDevice device, VkPhysicalDevice physicalDevice, VkSurfaceKHR surface);
    void claenup();

    void beginRender(uint32_t currentFrame);
    void endRender(uint32_t currentFrame, const Swapchain &swapchain);

    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

    VkResult present(VkPresentInfoKHR &presentInfo, uint32_t currentFrame);

    VkCommandBuffer commandBuffer(uint32_t currentFrame) const
    {
        return commandBuffers[currentFrame];
    }

private:
    void setQueue(QueueFamilyIndices indices);
    void createCommandPool(QueueFamilyIndices queueFamilyIndices);
    void createCommandBuffer();
    void createSyncObjects();

    VkDevice m_device = VK_NULL_HANDLE;
    VkCommandPool commandPool = VK_NULL_HANDLE;
    std::vector<VkCommandBuffer> commandBuffers;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    VkQueue graphicsQueue = VK_NULL_HANDLE;
    VkQueue presentQueue = VK_NULL_HANDLE;
};



#endif //REFACTOR2_COMMAND_H
