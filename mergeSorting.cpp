#include <iostream>
#include <chrono> // For measuring execution time

using namespace std;
using namespace std::chrono;

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
        int mid = (l + r) / 2;//l and are pointers
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int n;

    // User input for array size
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // User input for array elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Measure execution time
    auto start = high_resolution_clock::now();
    
    mergeSort(arr, 0, n - 1);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Display execution time
    cout << "Time taken: " << duration.count() << " ms" << endl;

    return 0;
}
