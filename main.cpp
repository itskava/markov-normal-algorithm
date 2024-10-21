#include "src/simulator.h"
#include <iostream>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide a chain.";
        return 1;
    }

    std::string chain;
    if (strcmp(argv[1], "main.cpp") == 0) {
        chain = "*";
    } else {
        chain = argv[1];
    }

    Simulator s;
    s.init(chain);
    s.run();

    return 0;
}