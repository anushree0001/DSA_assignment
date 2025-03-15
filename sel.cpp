    #include <iostream>
    #include <chrono>
    using namespace std;
    void printArray(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }cout << endl;
    }void selectionSort(int arr[], int n) {
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
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;
        int arr[n]; // Define an array of size n
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        selectionSort(arr, n);
        auto start = std::chrono::high_resolution_clock::now();
            
        //selectionSort ko call
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "Execution time: " << duration.count() * 1000 << " milliseconds\n";
        cout << "Sorted array: ";
        printArray(arr, n);

        return 0;
    }
