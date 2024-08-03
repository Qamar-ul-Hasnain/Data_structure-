#include <iostream>

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Target found at index mid
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);

    // Get user input for the target element
    int target;
    std::cout << "Enter the target element: ";
    std::cin >> target;

    int result = binarySearch(sortedArray, size, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array" << std::endl;
    }

    return 0;
}

