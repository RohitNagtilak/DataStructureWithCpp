//The time complexity of linear search is O(n), where 'n' is the number of elements in the array. 
#include <iostream>
int linearSearch(int arr[], int n, int target) 
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target) 
        {
            return i;  // Element found, return its index
        }
    }
    return -1; // Element not found
}

int main()
{
    int arr[] = { 10, 25, 30, 45, 50, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 45;

    int result = linearSearch(arr, n, target);

    if (result != -1)
    {
        std::cout << "Element found at index " << result << std::endl;
    }
    else
    {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}