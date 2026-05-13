#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node *front = NULL, *rear = NULL;

// Add coach (enqueue)
void addCoach(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }

    cout << x << " coach added\n";
}

// Remove coach (dequeue)
void removeCoach() {
    if (front == NULL) {
        cout << "Train empty\n";
        return;
    }

    cout << front->data << " coach removed\n";
    front = front->next;

    if (front == NULL)
        rear = NULL;
}

// Display train
void display() {
    if (front == NULL) {
        cout << "Train empty\n";
        return;
    }

    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int ch, val;

    while (true) {
        cout << "\n1.Add Coach 2.Remove Coach 3.Display 4.Exit\n";
        cin >> ch;

        if (ch == 1) {
            cin >> val;
            addCoach(val);
        }
        else if (ch == 2) removeCoach();
        else if (ch == 3) display();
        else break;
    }
}