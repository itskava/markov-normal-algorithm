#pragma once

#include <vector>
#include <string>

class Simulator {
private:
    std::vector<std::pair<std::string, std::string>> transition_table;
    std::string chain;

public:
    void init(const std::string& chain);
    void run();
    void display(const std::string& transition);
};