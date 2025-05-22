#include <iostream>

#include "Application.h"

int main()
{
    Application app;

    try
    {
        app.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
