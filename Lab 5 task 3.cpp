#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteByValue(Node*& head, int value) {
    // Empty list
    if (head == nullptr) {
        cout << "Value not found";
        return;
    }

    // Case 1: value is in the first node
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Case 2: value is in the middle or at the end
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* deleteNode = current->next;
        current->next = deleteNode->next;
        delete deleteNode;
    }
    // Case 3: value is not found
    else {
        cout << "Value not found" << endl;
    }
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

    head = n1;

    cout << "Before deletion: ";

    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Delete first node
    deleteByValue(head, 10);

    // Delete middle node
    deleteByValue(head, 30);

    // Value not in list
    deleteByValue(head, 99);

    cout << "After deletion: ";

    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
