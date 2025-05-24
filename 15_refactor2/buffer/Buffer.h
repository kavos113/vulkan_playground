#ifndef REFACTOR2_BUFFER_BUFFER_H
#define REFACTOR2_BUFFER_BUFFER_H

#include <vulkan/vulkan.h>

class Buffer
{
public:
    virtual ~Buffer() = default;

    virtual void create() = 0;
protected:
    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer &buffer, VkDeviceMemory &bufferMemory);
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

    VkDevice m_device = VK_NULL_HANDLE;
};



#endif //REFACTOR2_BUFFER_BUFFER_H
