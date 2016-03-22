/*!
 *  @mainpage Keno Game
 *  @authors Elton de Souza Vieira
 *  @authors Pedro Arthur Medeiros Fernandes
 *  @date March, 2016
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *  @version 1.0
 *
 *  @file drive_keno.cpp
 *  @brief Driver Program
 *
 *  File with the main function
 */

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "KenoBet.hpp"
#include "HelperFunctions.hpp"

//! The max spots allowed
constexpr auto MAX_SPOTS(15u);

//! The main function
//! @param argc The CLI parameters counter
//! @param argv The CLI parameters (used to read the bet file name)
//! @return 0 if success, 1 if not
int main(int argc, char const *argv[]) {
    // Store the bet file name
    std::string bet_file_name = "default_bet.dat";

    // Verify args passed by cli
    if (argc == 1)
        std::cerr << "No file specified, running with the default bet file\n\n";
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

    // Create vars to store data
    float IC;    // <! Initial Credit
    int NR;      // <! Number of Rounds
    KenoBet kb;  // <! Creates KenoBet object

    // Get data from file_data stream
    f_stream >> IC;
    f_stream >> NR;
    for (unsigned i = 0, tmp; kb.numChosen() < MAX_SPOTS && f_stream; i++) {
        f_stream >> tmp;
        kb.addNumber(tmp);
    }

    // Show received data
    std::cout << "    You are going to wage a total of $" << IC << " dollars.\n";
    std::cout << "    Going for a total of " << NR << " rounds, waging $"
              << IC/NR << " per round.\n";
    std::cout << "    Your bet has " << kb.numChosen() << " numbers. They are: [ ";
    for (auto i : kb.getSpots()) std::cout << i << " ";
    std::cout << "]\n";
    kb.printPayoutsTable();

    // Final Vars
    float FC = IC;  // <! Final Credit
    kb.setWage(IC/NR);

    for (int R = 0; R < NR; R++) {
        std::vector<int> rd_hits = kb.generateHits();

        std::cout << "\t--------------------------------------------------\n"
                  << "\tThis is round #" << R+1 << " of " << NR
                  << ", and your wage is $" << kb.getWage() << ". Good luck!\n";

        std::cout << "\tThe hits are: [ ";
        for (auto i : rd_hits)
            std::cout << i << " ";
        std::cout << "]\n";

        std::vector<int> m_hits = kb.getHits(rd_hits);

        std::cout << "\n\tYou hit the following number(s) [ ";
        for (auto i : m_hits)
            std::cout << i << " ";

        // Gets the payout rate by the number of hits
        float payout_rate = kb.getPayout(m_hits.size());
        // Calculates the currency
        float currency = kb.getWage() * payout_rate;
        // Updates the Final Credit
        FC += currency - kb.getWage();

        std::cout << "], a total of " << m_hits.size() << " hit out of "
                  << kb.numChosen() << "\n\tPayout rate is " << payout_rate
                  << ", thus you came out with: $" << currency << "\n"
                  << "\tYour net balance so far is: $" << FC << " dollars.\n";
    }

    std::cout << ">>> End of rounds!\n"
              << "--------------------------------------------------\n\n";

    // Calculates the difference between the Final Credit and the Initial Credit
    float diff = FC - IC;

    std::cout << "===== SUMMARY =====\n"
              << ">>> You spent in this game a total of $" << IC << " dollars.\n";
    if (diff >= 0)
        std::cout << ">>> Hooray, you won $" << diff
                  << " dollars. See you next time! ;-)\n";
    else
        std::cout << ">>> Ahh, you lost $" << -diff
                  << " dollars. Better luck next time! o/\n";
    std::cout << ">>> You are leaving the Keno table with $" << FC << " dollars.\n\n";

    return EXIT_SUCCESS;
}
