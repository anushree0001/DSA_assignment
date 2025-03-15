#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono> // For measuring execution time

using namespace std;
using namespace chrono;

// Function declarations
void generateRandomNumbers(vector<int>& arr, int N);
int binarySearch(const vector<int>& arr, int target);
int interpolationSearch(const vector<int>& arr, int target);

// Function to generate N random numbers, store them in the vector, and sort them
void generateRandomNumbers(vector<int>& arr, int N) {
    srand(time(0));
    for (int i = 0; i < N; i++) {
        arr.push_back(rand() % 100); // Generate a random number between 0 and 99
    }
    sort(arr.begin(), arr.end()); // Sort the vector in ascending order
}

// Binary Search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Interpolation Search
int interpolationSearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        // Estimate the probable position using the interpolation formula
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));
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

    vector<int> numbers;
    generateRandomNumbers(numbers, N);

    // Display the generated and sorted numbers
    cout << "Generated & Sorted Numbers: ";
    for (int num : numbers) cout << num << " ";
    cout << "\n";

    cout << "Enter the number to search: ";
    cin >> target;

    // Measure the runtime of Binary Search
    auto start = high_resolution_clock::now();
    int binaryResult = binarySearch(numbers, target);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); // in microseconds

    if (binaryResult != -1)
        cout << "Binary Search: Element found at index " << binaryResult << "\n";
    else
        cout << "Binary Search: Element not found!\n";

    cout << "Binary Search execution time: " << duration.count() << " microseconds\n";

    // Measure the runtime of Interpolation Search
    start = high_resolution_clock::now();
    int interpolationResult = interpolationSearch(numbers, target);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start); // in microseconds

    if (interpolationResult != -1)
        cout << "Interpolation Search: Element found at index " << interpolationResult << "\n";
    else
        cout << "Interpolation Search: Element not found!\n";

    cout << "Interpolation Search execution time: " << duration.count() << " microseconds\n";

    return 0;
}
