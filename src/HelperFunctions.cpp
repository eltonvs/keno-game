/*!
 *  @file HelperFunctions.cpp
 *  @brief General Functions
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  Source with the general functions
 */

#include <string>
#include <algorithm>

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
        filtered_string += in_array(str[i], filter, f_sz) ? str[i] : ' ';
    // Return the filtered_string
    return filtered_string;
}

bool compare(int a, int b) {
    // Comparison to an ascendant sort
    return a < b;
}

int divide(int *V, int l, int r, bool (*comp)(int, int)) {
    // i to iterate vector and j gets the final position of the pivot
    int i = l, j = l;
    while (i < r) {
        // Separate vector with comp() condition
        if (comp(*(V+i), *(V+r)))
            std::swap(*(V+i), *(V+j++));
        i++;
    }
    // put the pivot on your final position
    std::swap(*(V+r), *(V+j));

    // Return the pivot position
    return j;
}

void quick_sort_engine(int *V, int l, int r, bool (*comp)(int, int)) {
    // Verify base case (a vector with 1 element is already sorted)
    if (r > l) {
        // Call function to partition vector and get the pivot element
        int k = divide(V, l, r, comp);
        // Divide & Conquer: call quicksort again to sort the extremities
        quick_sort_engine(V, 0, k-1, comp);
        quick_sort_engine(V, k+1, r, comp);
    }
}

void quick_sort(int *V, int size, bool (*comp)(int, int)) {
    quick_sort_engine(V, 0, size-1, comp);
}
