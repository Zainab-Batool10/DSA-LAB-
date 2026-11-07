#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteAtStart(Node*& head) {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

int main() {
    Node* head;
    Node* temp;

    Node* n1 = new Node;
    Node* n2 = new Node;
    Node* n3 = new Node;
    Node* n4 = new Node;

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;

    head = n1;   // not visible in screenshot (lines 37-39), needed for the program to work

    cout << "Before deletion: ";

    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // Delete from start twice
    deleteAtStart(head);
    deleteAtStart(head);

    cout << "\nAfter deletion: ";

    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
