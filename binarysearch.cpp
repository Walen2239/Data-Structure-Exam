#include "binarysearch.hpp"

int binary_search(const int array[], int length, int target, bool ascending) {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;  // Found it!
        }

        // Adjust based on sorting order
        if (ascending) {
            if (target < array[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (target > array[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    return -1;  // Not found
}
