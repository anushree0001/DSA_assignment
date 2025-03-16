#include <iostream>
#include <chrono> // For measuring execution time

using namespace std;
using namespace std::chrono;

// Function to generate N random numbers, store them in an array
void generateRandomNumbers(int arr[], int N) {
    srand(time(0)); // Seed for randomness
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100; // Generate a random number between 0 and 99
    }
}


void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2]; // Temporary arrays

    // Copy values into temp arrays
    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
    }

    // Merge the temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from a[] (if any)
    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements from b[] (if any)
    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2; // l and r are pointers
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
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
    mergeSort(arr, 0, N - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); // in nanoseconds
    cout << "\nExecution time: " << duration.count() << " nanoseconds\n";

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";

    return 0;
}
