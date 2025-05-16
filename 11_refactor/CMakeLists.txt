cmake_minimum_required(VERSION 3.28)
project(refactor)

set(CMAKE_CXX_STANDARD 20)

add_executable(refactor
        main.cpp
        Application.cpp
        Application.h
        debugUtils.h
        utils.h
)
target_include_directories(refactor PRIVATE $ENV{LIBRARY_DIR}/glfw-3.4.bin.WIN64/include)
target_include_directories(refactor PRIVATE $ENV{LIBRARY_DIR}/glm-1.0.1-light)
target_include_directories(refactor PRIVATE $ENV{VULKAN_SDK}/Include)
target_link_libraries(refactor PRIVATE $ENV{LIBRARY_DIR}/glfw-3.4.bin.WIN64/lib-vc2022/glfw3.lib)
target_link_libraries(refactor PRIVATE $ENV{VULKAN_SDK}/Lib/vulkan-1.lib)
message($ENV{LIBRARY_DIR}/glfw-3.4.bin.WIN64/include)

file(COPY frag.spv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY vert.spv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})