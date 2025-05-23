#ifndef REFACTOR_UTILS_H
#define REFACTOR_UTILS_H
#include <fstream>
#include <ios>
#include <stdexcept>
#include <string>
#include <vector>

inline std::vector<char> readFile(const std::string& filename)
{
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open())
    {
        throw std::runtime_error("failed to open file");
    }

    size_t fileSize = file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();

    return buffer;
}

#endif //REFACTOR_UTILS_H
