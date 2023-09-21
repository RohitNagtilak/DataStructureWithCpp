#include <iostream>

int main() 
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int indexToDelete = 2; // Index of the element to delete

    // Check if the index is valid
    if (indexToDelete < 0 || indexToDelete >= n) 
    {
        std::cout << "Invalid index to delete" << std::endl;
    }
    else
    {
        // Shift elements to the left from the index to be deleted
        for (int i = indexToDelete; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        n--; // Decrease the size of the array

        // Print the updated array
        for (int i = 0; i < n; i++) 
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
