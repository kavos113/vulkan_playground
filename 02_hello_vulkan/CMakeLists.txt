cmake_minimum_required(VERSION 3.28)
project(hello-vulkan)

set(CMAKE_CXX_STANDARD 20)

add_executable(hello-vulkan main.cpp)
target_include_directories(hello-vulkan PRIVATE $ENV{LIBRARY_DIR}/glfw-3.4.bin.WIN64/include)
target_include_directories(hello-vulkan PRIVATE $ENV{LIBRARY_DIR}/glm-1.0.1-light)
target_include_directories(hello-vulkan PRIVATE $ENV{VULKAN_SDK}/Include)
target_link_libraries(hello-vulkan PRIVATE $ENV{LIBRARY_DIR}/glfw-3.4.bin.WIN64/lib-vc2022/glfw3.lib)
target_link_libraries(hello-vulkan PRIVATE $ENV{VULKAN_SDK}/Lib/vulkan-1.lib)
message($ENV{LIBRARY_DIR}/glfw-3.4.bin.WIN64/include)