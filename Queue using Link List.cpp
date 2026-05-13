#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }

    cout << x << " inserted\n";
}

// Dequeue
void dequeue() {
    if (front == NULL) {
        cout << "Queue Empty\n";
        return;
    }

    cout << front->data << " removed\n";
    front = front->next;

    if (front == NULL)
        rear = NULL;
}

// Display
void display() {
    if (front == NULL) {
        cout << "Queue Empty\n";
        return;
    }

    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
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
