#include "simulator.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <unistd.h>

void Simulator::init(const std::string& chain) {
    this->chain = chain;

    std::fstream file;
    file.open("transitions.txt", std::ios::in);

    if (!file.is_open()) {
        std::cerr << "Unable to open transitions.txt";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::size_t index = line.find(" ");

        if (index == std::string::npos) {
            std::cerr << "Invalid line in transitions.txt, please ensure that lines contain a ' '";
            return;
        }

        std::string from = line.substr(0, index);
        std::string to = line.substr(index + 1); 

        if (from == "_") from = ' ';
        if (to == "_") to = ' ';
        
        transition_table.push_back({from, to});
    }

    file.close();
}

void Simulator::run() {
    std::cout << chain << std::endl << std::endl;  
    bool done = false;

    while (!done) {
        done = true;

        for (size_t i = 0; i != transition_table.size(); ++i) {
            std::string from = transition_table[i].first;
            std::string to = transition_table[i].second;

            if (chain[0] != ' ') chain = ' ' + chain;

            if (chain.find(from) != std::string::npos) {
                done = false;

                if (to[to.length() - 1] == '.') {
                    to = to.substr(0, to.length() - 1);
                    done = true;
                }

                chain = chain.replace(chain.find(from), from.length(), to);
                display("\"" + from + "\"" + " -> " + "\"" + to + "\"");
                break;
            }
        }
    }

    std::cout << chain.substr(1, chain.length() - 1) << std::endl;
}

void Simulator::display(const std::string& transition) {
    std::cout << chain.substr(1, chain.length() - 1) << " | " << transition << std::endl;
    std::cout << std::flush;
    usleep(200000);
}