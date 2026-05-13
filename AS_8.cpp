#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Insert
void enqueue(int x) {
    if ((rear + 1) % MAX == front) {
        cout << "Queue Full\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = x;

    cout << x << " inserted\n";
}

// Delete
void dequeue() {
    if (front == -1) {
        cout << "Queue Empty\n";
        return;
    }

    cout << queue[front] << " removed\n";

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if (front == -1) {
        cout << "Queue Empty\n";
        return;
    }

    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    int ch, val;

    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n";
        cin >> ch;

        if (ch == 1) {
            cin >> val;
            enqueue(val);
        }
        else if (ch == 2) dequeue();
        else if (ch == 3) display();
        else break;
    }
}