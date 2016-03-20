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

//! Quick Sort function
//! @param V a pointer to the first position of the vector to be sorted
//! @param l the left position of the vector
//! @param r the right position of the vector
void quick_sort(int *V, int l, int r);

//! Quick Sort dependency function
//! @param V a pointer to the first position of the vector to be divided
//! @param l the left position of the vector
//! @param r the right position of the vector
int quick_sort_divide(int *V, int l, int r);

#endif
