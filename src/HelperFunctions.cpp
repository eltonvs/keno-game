// Copyright 2016

#include <vector>
#include <string>

#include "HelperFunctions.hpp"

bool in_array(int x, const int *v, unsigned sz) {
    for (auto i(0u); i < sz; i++)
        if (x == v[i])
            return true;
    return false;
}

std::string filter_string(std::string str, const int *filter, int f_sz) {
    // Create the string to be returned
    std::string filtered_string;
    for (auto i(0u); i < str.size(); i++)
        if (in_array(str[i], filter, f_sz))
            filtered_string += str[i];
    return filtered_string;
}
