#include <iostream>
using namespace std;

int arr[100], n = 0;

// Insert
void insert(int x) {
    arr[n++] = x;
    cout << x << " inserted\n";
}

// Delete highest priority (max)
void remove() {
    if (n == 0) {
        cout << "Queue empty\n";
        return;
    }

    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }

    cout << arr[maxIndex] << " removed\n";

    // Shift elements
    for (int i = maxIndex; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
}

// Display
void display() {
    if (n == 0) {
        cout << "Queue empty\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int ch, val;

    while (true) {
        cout << "\n1.Insert 2.Delete 3.Display 4.Exit\n";
        cin >> ch;

        if (ch == 1) {
            cin >> val;
            insert(val);
        }
        else if (ch == 2) remove();
        else if (ch == 3) display();
        else break;
    }
}