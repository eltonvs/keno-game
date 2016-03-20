// Copyright 2016

#include <vector>
#include "keno.hpp"

// KenoBet functions here
class KenoBet {
 public:
    // -----------
    // Constructor
    // -----------
    //! Creates a Keno bet. It defines the maximum spots a bet may have.
    explicit KenoBet(unsigned int _maxNumSpots = 15){
    

    }
    // Adds a number to the spots only if the number is not already there.
    // @param _spot The number we wish to include in the bet.
    // @return T if number chosen is successfully inserted; F otherwise.	

    bool addNumber(int _spot){
    	for (int i = 0; i < _maxNumSpots; ++i)
    	{
    		if(_spot == m_spots)
    			return F;
    	}	
    		m_spots.push_back(_spot);
    		return T;
    }
	// -------
    // Getters
    // -------
    // Retrieves the player's wage on this bet.
    // @return The wage value. 	
    float getWage(void) const{
    	return m_wage;	
    }

    // Determine how many spots match the hits passed as argument.
    // @param _hits List of hits randomly chosen by the computer.
    // @return An vector with the list of hits.
    std::vector<int> getHits(const std::vector<int> &_hits) const{
    	std::vector<i> a;
    	int c;
    	for (int i = 0; i < _maxNumSpots; ++i)
    	{
    		for (int e = 0; e < 20; ++e)
    		{
    			if (m_spots[i] == _hits[e])
    			{
    				a[c] = m_spots[i];
    				c++;
    			}
    		}
    	}
    	return a;
    }

    // Return an vector<int> with the spots the player has picked so far.
    // @return The vector<int> with the player's spots picked so far.  

    std::vector<int> getSpots(void) const{

    	return m_spots;

    }

    // -------
    // Setters
    // -------
    // Sets the amount of money the player is betting.
    // @param _wage The wage.
    // @return True if we have a wage above zero; false otherwise.

    bool setWage(float _wage){
    	m_spots = _wage;
    	if (m_spots > 0)
    		return True;
    	else
    		return False;
    }
    // -------
    // Methods
    // -------
    //! Resets a bet to an empty state.
	
    void reset(void){

    
    }
    // Returns to the current number of spots in the player's bet.
    // @return Number of spots present in the bet.	

    std::size_t numChosen(void) const{
    	return m_spots.size()
    }

 private:
    std::vector<int> m_spots;  // <! The player's bet.
    float m_wage;              // <! The player's wage
    unsigned int m_maxSpots;   // <! Max # of spots allowed for this bet.
};