#include <iostream>
using namespace std;

// ---------- MERGE SORT ----------
void merge(int arr[], int l, int m, int r) {
    int temp[100];
    int i = l, j = m + 1, k = l;

    while (i <= m && j <= r) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    for (int i = l; i <= r; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// ---------- HEAP SORT ----------
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

// ---------- MAIN ----------
int main() {
    int arr1[5] = {5, 3, 8, 1, 2};
    int arr2[5] = {5, 3, 8, 1, 2};

    // Merge Sort
    mergeSort(arr1, 0, 4);
    cout << "Merge Sort: ";
    for (int i = 0; i < 5; i++)
        cout << arr1[i] << " ";

    // Heap Sort
    heapSort(arr2, 5);
    cout << "\nHeap Sort: ";
    for (int i = 0; i < 5; i++)
        cout << arr2[i] << " ";

    return 0;
}
