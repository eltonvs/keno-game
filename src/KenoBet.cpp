/*!
 *  @file KenoBet.cpp
 *  @brief Source for KenoBet class
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with the KenoBet class Methods
 */

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include "KenoBet.hpp"
#include "HelperFunctions.hpp"

// -----------------------------------------------------------------------------
// Constructor
// -----------------------------------------------------------------------------
// Creates a Keno bet. It defines the maximum spots a bet may have.
KenoBet::KenoBet(unsigned int _maxNumSpots) {
    this->m_maxSpots = _maxNumSpots > 15 ? 15 : _maxNumSpots;
    this->m_spots.resize(0);
}

// -----------------------------------------------------------------------------
// Getters
// -----------------------------------------------------------------------------
// Retrieves the player's wage on this bet.
float KenoBet::getWage(void) const {
    return this->m_wage;
}
// Determine how many spots match the hits passed as argument.
std::vector<int> KenoBet::getHits(const std::vector<int> &_hits) const {
    // The vector with the matched hits
    std::vector<int> matches;
    for (int i = 0; i < 20; i++)
        // Verify if the hit element is one of the bet element.
        // If true, append the element in a
        if (in_array(_hits[i], this->m_spots.data(), this->m_spots.size()))
            matches.push_back(_hits[i]);
    // Return the vector with the marched hits
    return matches;
}
// Return an vector<int> with the spots the player has picked so far.
std::vector<int> KenoBet::getSpots(void) const {
    return this->m_spots;
}

// -----------------------------------------------------------------------------
// Setters
// -----------------------------------------------------------------------------
// Sets the amount of money the player is betting.
bool KenoBet::setWage(float _wage) {
    return (this->m_wage = _wage);
}

// -----------------------------------------------------------------------------
// Methods
// -----------------------------------------------------------------------------
// Resets a bet to an empty state.
void KenoBet::reset(void) {
    m_spots.clear();
    m_spots.resize(0);
}
// Adds a number to the spots only if the number is not already there.
bool KenoBet::addNumber(int _spot) {
    if (!in_array(_spot, this->m_spots.data(), this->m_spots.size()) &&
        this->m_spots.size() < this->m_maxSpots && _spot > 0 && _spot < 80) {
        this->m_spots.push_back(_spot);
        std::sort(this->m_spots.begin(), this->m_spots.end());
        return true;
    }
    return false;
}
// Returns to the current number of spots in the player's bet.
std::size_t KenoBet::numChosen(void) const {
    return m_spots.size();
}
std::vector<int> KenoBet::generateHits(void) const {
    std::vector<int> hits;
    for (int i = 0; i < 80; i++)
        hits.push_back(i+1);
    // Create a real random number
    std::random_device r;
    // Shuffle vector content using the random number as seed
    std::shuffle(hits.begin(), hits.end(), std::default_random_engine(r()));
    // Resize vector to 20 elements
    hits.resize(20);
    // Sort vector elements
    std::sort(hits.begin(), hits.end());
    return hits;
}
// Print a Payout Table
void KenoBet::printPayoutsTable() {
    // Print Table Header
    std::cout << "\t--------+---------\n"
              << "\tHits\t| Payout\n"
              << "\t--------+---------\n";
    // Print Table Content
    for (auto i(0u); i <= this->numChosen(); i++)
        std::cout << "\t" << i << "\t| "
                  << this->m_payouts[this->numChosen()-1][i] << "\n";
}
