#include "first_app.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <chrono>
#include <thread>

int main() {

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    lve::FirstApp app{};
    
    try 
    {
        app.run();
    } catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
