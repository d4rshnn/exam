#include <iostream>
using namespace std;

#define MAX 5

int q[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1) {
        cout << "Queue Full\n";
        return;
    }

    if (front == -1)
        front = 0;

    q[++rear] = x;
    cout << x << " inserted\n";
}

// Dequeue
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Empty\n";
        return;
    }

    cout << q[front++] << " removed\n";
}

// Display
void display() {
    if (front == -1 || front > rear) {
        cout << "Queue Empty\n";
        return;
    }

    for (int i = front; i <= rear; i++) {
        cout << q[i] << " ";
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