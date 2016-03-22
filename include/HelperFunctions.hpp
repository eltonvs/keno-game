/*!
 *  @file HelperFunctions.hpp
 *  @brief Headers of general functions
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  Header with the with the general functions prototypes
 */

#ifndef _HelperFunctions_hpp_
#define _HelperFunctions_hpp_

#include <string>

// Global Var
//! A array with the allowed chars (in ASCII code)
constexpr int ALLOWED_CHARS[] = {
    9,   // Tab
    10,  // Line break
    32,  // White space
    46,  // Dot
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57  // Numbers [0, 9]
};

//! Verify if a number is inside an array
//! @param x The number to be searched in array
//! @param v The array to be searched in
//! @param sz The array size
//! @return True if the number is inside the array; false otherwise
bool in_array(int x, const int *v, unsigned sz);

//! Function to filter a string by an filter
//! @param str The string to be filtered
//! @param filter An array with the ASCII code from the allowed chars
//! @param f_sz The filter array size
//! @return The filtered string
std::string filter_string(std::string str, const int *filter, int f_sz);

#endif
