// Copyright 2016

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "keno.hpp"

constexpr auto MAX_SPOTS(15u);
constexpr auto MAX_PROPER(80u);

int main(int argc, char const *argv[]) {
    // Store the bet file name
    std::string bet_file_name = "default_bet.dat";

    // Verify args passed by cli
    if (argc == 1)
        std::cerr << "No file specified, running with the default bet file\n";
    else
        bet_file_name = argv[1];

    // Open bet file
    std::ifstream bet("data/"+bet_file_name);

    // Verify if the bet file was opened
    if (bet) {
        std::cout << "File opened with success\n";
    } else {
        std::cerr << "Error at file opening, finishing game...\n";
        bet.close();
        exit(1);
    }

    return EXIT_SUCCESS;
}
