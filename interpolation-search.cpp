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

// Interpolation Search
int interpolationSearch(int arr[], int N, int target) {
    int low = 0, high = N - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        // Estimate the probable position using the interpolation formula
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        // Ensure pos is within bounds before accessing the array
        if (pos < low || pos > high) break;

        if (arr[pos] == target) return pos;
        if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

// Main function
int main() {
    int N, target;
    cout << "Enter the number of random elements: ";
    cin >> N;

    int* arr = new int[N]; // Dynamically allocate array
    generateRandomNumbers(arr, N);

    // Display the generated and sorted numbers
    cout << "Generated & Sorted Numbers: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";

    cout << "\nEnter the number to search: ";
    cin >> target;

    // Measure the runtime of Interpolation Search
    auto start = high_resolution_clock::now();
    int interpolationResult = interpolationSearch(arr, N, target);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); // in nanoseconds
    cout << "\nExecution time: " << duration.count() << " nanoseconds\n";

    if (interpolationResult != -1)
        cout << "Element found at index " << interpolationResult;
    else
        cout << "Element not found!";
    return 0;
}
