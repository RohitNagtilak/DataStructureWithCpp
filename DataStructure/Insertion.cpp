#include <iostream>

int main() 
{
    int arr[100];  // Declare an array with a maximum size
    int n;          // Current number of elements in the array
    int index;      // Index where you want to insert the element
    int element;    // The element you want to insert

    // Input the number of elements in the array (n)
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // Input the elements
    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // Input the index where you want to insert the element
    std::cout << "Enter the index where you want to insert the element: ";
    std::cin >> index;

    // Input the element you want to insert
    std::cout << "Enter the element you want to insert: ";
    std::cin >> element;

    // Check if the index is valid
    if (index < 0 || index > n) {
        std::cout << "Invalid index. Insertion failed." << std::endl;
        return 1; // Exit with an error code
    }

    // Shift elements to the right to make space for the new element
    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the specified index
    arr[index] = element;

    // Increment the number of elements in the array
    n++;

    // Display the updated array
    std::cout << "Updated array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
