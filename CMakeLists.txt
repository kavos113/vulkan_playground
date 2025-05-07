cmake_minimum_required(VERSION 3.31)
project(vulkan_playground)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(01_hello_glfw)
add_subdirectory(02_hello_vulkan)
add_subdirectory(03_phisical_device)
add_subdirectory(04_logical_device)
add_subdirectory(05_window_surface)
add_subdirectory(06_swapchain)