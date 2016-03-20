/*!
 *  @file HelperFunctions.cpp
 *  @brief General Functions
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  Source with the general functions
 */

#include <vector>
#include <string>

#include "HelperFunctions.hpp"

bool in_array(int x, const int *v, unsigned sz) {
    for (auto i(0u); i < sz; i++)
        // If the needle is on haystack, return True
        if (x == v[i])
            return true;
    // Otherwise, return False
    return false;
}

std::string filter_string(std::string str, const int *filter, int f_sz) {
    // Create the string to be returned
    std::string filtered_string;
    for (auto i(0u); i < str.size(); i++)
        // If the char is on allowed chars (filter), append to filtered_string
        if (in_array(str[i], filter, f_sz))
            filtered_string += str[i];
    // Return the filtered_string
    return filtered_string;
}
