#include <iostream>
#include <ctime>
#include <chrono> // For measuring execution time

using namespace std;
using namespace chrono;

// Function to generate N random numbers, store them in an array
void generateRandomNumbers(int arr[], int N) {
    srand(time(0)); // Seed for randomness
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100; // Generate a random number between 0 and 99
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallestIndex = i; // Unsorted part starting
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[smallestIndex]) {
                smallestIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;
    }
}

int main() {
    int N;
    cout << "Enter the length of array: ";
    cin >> N;
    
    int* arr = new int[N]; // Dynamically allocate array
    generateRandomNumbers(arr, N);
    
    // Display the generated numbers
    cout << "Generated Numbers: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    
    // Measure the runtime of Selection Sort
    auto start = high_resolution_clock::now();
    selectionSort(arr, N);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); // in nanoseconds
    cout << "\nExecution time: " << duration.count() << " nanoseconds\n";
    
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    return 0;
}
