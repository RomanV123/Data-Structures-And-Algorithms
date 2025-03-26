#include <iostream>
using namespace std;


// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;     // Size of the right subarray

    // Dynamically allocate temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left...right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    // Copy any remaining elements of L[]
    while (i < n1) {
        arr[k++] = L[i++];
    }
    // Copy any remaining elements of R[]
    while (j < n2) {
        arr[k++] = R[j++];
    }

    // Free the memory allocated for temporary arrays
    delete[] L;
    delete[] R;
}

// Recursive merge sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the midpoint
        int mid = left + (right - left) / 2;
        // Recursively sort the first half
        mergeSort(arr, left, mid);
        // Recursively sort the second half
        mergeSort(arr, mid + 1, right);
        // Merge the two sorted halves
        merge(arr, left, mid, right);
    }
}



int main() {
    int SIZE;
    cin >> SIZE;

    // Note: Variable Length Arrays (VLAs) are not standard in C++.
    // For standard C++, consider using dynamic allocation or std::vector.
    int* arr = new int[SIZE];  // Dynamically allocated array

    // Initialize i to 0
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, SIZE - 1);

    cout << "Sorted Array: " << endl;

    // Initialize i to 0
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
