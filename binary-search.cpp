#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono> // For measuring execution time

using namespace std;
using namespace chrono;

// Function to generate N random numbers, store them in an array, and sort them
void generateRandomNumbers(int arr[], int N) {
    srand(time(0)); // Seed for randomness
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100; // Generate a random number between 0 and 99
    }
    sort(arr, arr + N); // Sort the array in ascending order
}

// Binary Search
int binarySearch(const int arr[], int N, int target) {
    int left = 0, right = N - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Main function
int main() {
    int N, target;
    cout << "Enter the number of random elements: ";
    cin >> N;

    int* arr = new int[N]; // Dynamic allocation of array
    generateRandomNumbers(arr, N);

    // Display the generated and sorted numbers
    cout << "Generated & Sorted Numbers: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";

    cout << "\nEnter the number to search: ";
    cin >> target;

    // Measure the runtime of Binary Search
    auto start = high_resolution_clock::now();
    int binaryResult = binarySearch(arr, N, target);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); // in nanoseconds
    cout << "\nExecution time: " << duration.count() << " nanoseconds\n";

    if (binaryResult != -1)
        cout << "Element found at index " << binaryResult;
    else
        cout << "Element not found!";
    return 0;
}
