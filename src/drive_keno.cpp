// Copyright 2016

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "KenoBet.hpp"
#include "HelperFunctions.hpp"

constexpr auto MAX_SPOTS(15u);   // <! The max spots allowed
constexpr auto MAX_PROPER(80u);  // <! The max Proper (range [1, 80])
//! A array with the allowed chars (in ASCII code)
constexpr int ALLOWED_CHARS[] = {
    9,   // Tab
    10,  // Line break
    32,  // White space
    46,  // Dot
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57  // Numbers [0, 9]
};

int main(int argc, char const *argv[]) {
    // Store the bet file name
    std::string bet_file_name = "default_bet.dat";

    // Verify args passed by cli
    if (argc == 1)
        std::cerr << "No file specified, running with the default bet file\n";
    else
        bet_file_name = argv[1];

    // Show message on console
    std::cout << ">>> Preparing to read bet file [data/"
              << bet_file_name << "], please wait...\n"
              << "--------------------------------------------------\n";

    // Open bet file
    std::ifstream bet("data/"+bet_file_name);

    // Verify if the bet file wasn't opened and show a status message
    if (!bet) {
        std::cerr << ">>> The file cannot be read\n";
        bet.close();
        exit(1);
    }
    std::cout << ">>> Bet successfully read!\n";

    // Copy content from file to file_data
    std::string file_data(
        (std::istreambuf_iterator<char>(bet)),
        (std::istreambuf_iterator<char>()));

    // Close opened file (The content is already on file_data)
    bet.close();

    // Filter file_data
    file_data = filter_string(file_data, ALLOWED_CHARS,
        sizeof(ALLOWED_CHARS)/sizeof(int));

    // Create a stringstream with file_data content
    std::stringstream f_stream(file_data);

    // Create vars to keep data (Initial Credit, Number of Rounds and Bets)
    float IC;
    int NR;
    std::vector<int> bets;

    // Get data from file_data stream
    f_stream >> IC;
    f_stream >> NR;
    for (auto i(0u); bets.size() < MAX_SPOTS && f_stream; i++) {
        unsigned tmp;
        f_stream >> tmp;
        if (!in_array(tmp, bets.data(), bets.size()) && tmp < MAX_PROPER)
            bets.push_back(tmp);
    }

    // Show received data
    std::cout << "You are going to wage a total of $" << IC << " dollars.\n";
    std::cout << "Going for a total of " << NR << " rounds, waging $" << IC/NR << " per round.\n";
    std::cout << "Your bet has " << bets.size() << " numbers. They are: [ ";
    for (auto i : bets)
        std::cout << i << " ";
    std::cout << "]\n";

    return EXIT_SUCCESS;
}
