// Binary search has a time complexity of O(log n) for a sorted array.
#include <iostream>
int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Element found at index 'mid'
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}

int main()
{
    int arr[] = { 1, 3, 5, 7, 9, 11, 13 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    }
    else {
        std::cout << "Element " << target << " not found in the array" << std::endl;
    }
    return 0;
}