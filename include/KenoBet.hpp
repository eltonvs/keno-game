/*!
 *  @file KenoBet.hpp
 *  @brief Headers of KenoBet Class
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  Header with the with KenoBet Class
 */

#ifndef _KenoBet_hpp_
#define _KenoBet_hpp_

#include <string>
#include <vector>

//! The main Class
class KenoBet {
 public:
    // -------------------------------------------------------------------------
    // Constructor
    // -------------------------------------------------------------------------
    //! Creates a Keno bet. It defines the maximum spots a bet may have.
    //! @param _maxNumSpots Receives the max spots number
    explicit KenoBet(unsigned int _maxNumSpots = 15);

    // -------------------------------------------------------------------------
    // Getters
    // -------------------------------------------------------------------------
    //! Retrieves the player's wage on this bet.
    //! @return The wage value.
    float getWage(void) const;
    //! Determine how many spots match the hits passed as argument.
    //! @param _hits List of hits randomly chosen by the computer.
    //! @return An vector with the list of hits.
    std::vector<int> getHits(const std::vector<int> &_hits) const;
    //! Return an vector<int> with the spots the player has picked so far.
    //! @return The vector<int> with the player's spots picked so far.
    std::vector<int> getSpots(void) const;
    //! Gets the corresponding Payout value given the hits number
    //! @param _hits The number of hits
    //! @return The Payout Value
    float getPayout(int _hits);

    // -------------------------------------------------------------------------
    // Setters
    // -------------------------------------------------------------------------
    //! Sets the amount of money the player is betting.
    //! @param _wage The wage.
    //! @return True if we have a wage above zero; false otherwise.
    bool setWage(float _wage);

    // -------------------------------------------------------------------------
    // Methods
    // -------------------------------------------------------------------------
    //! Resets a bet to an empty state.
    void reset(void);
    //! Adds a number to the spots only if the number is not already there.
    //! @param _spot The number we wish to include in the bet.
    //! @return T if number chosen is successfully inserted; F otherwise.
    bool addNumber(int _spot);
    //! Returns to the current number of spots in the player's bet.
    //! @return Number of spots present in the bet.
    std::size_t numChosen(void) const;
    //! Returns a vector with 20 unique random numbers in range [1, 80].
    //! @return A vector with 20 unique random numbers in range [1, 80].
    std::vector<int> generateHits(void) const;
    //! Print a Payout Table
    void printPayoutsTable();

 private:
    std::vector<int> m_spots;  // <! The player's bet.
    float m_wage;              // <! The player's wage
    unsigned int m_maxSpots;   // <! Max # of spots allowed for this bet.
    //! The payouts array.
    std::vector<std::vector<float>> m_payouts = {
        {0, 3},
        {0, 1, 9},
        {0, 1, 2, 16},
        {0, 0.5, 2, 6, 12},
        {0, 0.5, 1, 3, 15, 50},
        {0, 0.5, 1, 2, 3, 30, 75},
        {0, 0.5, 0.5, 1, 6, 12, 36, 100},
        {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},
        {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200},
        {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},
        {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},
        {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000},
        {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000},
        {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500},
        {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}
    };
};

#endif
