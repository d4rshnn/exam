#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

// Push
void push(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    cout << x << " pushed\n";
}

// Pop
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << top->data << " popped\n";
    top = top->next;
}

// Display
void display() {
    if (top == NULL) {
        cout << "Stack empty\n";
        return;
    }
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int ch, val;

    while (true) {
        cout << "\n1.Push 2.Pop 3.Display 4.Exit\n";
        cin >> ch;

        if (ch == 1) {
            cin >> val;
            push(val);
        }
        else if (ch == 2) pop();
        else if (ch == 3) display();
        else break;
    }
}
