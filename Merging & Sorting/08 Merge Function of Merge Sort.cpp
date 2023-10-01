#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Merge two sorted subarrays into one sorted array.
 *
 * @param arr Reference to the array to be sorted.
 * @param low Index of the first element of the first subarray.
 * @param mid Index of the last element of the first subarray.
 * @param high Index of the last element of the second subarray.
 */
void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary vectors for the left and right subarrays
    vector<int> left(n1);
    vector<int> right(n2);

    // Copy data to temporary vectors left[] and right[]
    for (int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }

    for (int i = 0; i < n2; i++) {
        right[i] = arr[mid + 1 + i];
    }

    // Merge the two subarrays back into the original array
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copy any remaining elements from the left and right subarrays
    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}

/**
 * @brief Perform merge sort on an array.
 *
 * @param arr Reference to the array to be sorted.
 * @param low Index of the first element of the array.
 * @param high Index of the last element of the array.
 */
void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

int main() {
    vector<int> inputArray = {1, 3, 5, 7, 2, 4, 6};
    int n = inputArray.size();

    // Sort the inputArray using merge sort
    mergeSort(inputArray, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << inputArray[i] << " ";
    }
    return 0;
}
