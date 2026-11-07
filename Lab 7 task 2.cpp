#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* n1 = new Node{101, nullptr, nullptr};
    Node* n2 = new Node{102, n1, nullptr};
    n1->next = n2;
    Node* n3 = new Node{103, n2, nullptr};
    n2->next = n3;
    Node* n4 = new Node{104, n3, nullptr};
    n3->next = n4;
    Node* n5 = new Node{105, n4, nullptr};
    n4->next = n5;

    Node* head = n1;
    Node* tail = n5;

    Node* p100 = new Node{100, nullptr, head};
    head->prev = p100;
    head = p100;

    Node* p1035 = new Node{1035, n3, n3->next};
    n3->next->prev = p1035;
    n3->next = p1035;

    Node* p106 = new Node{106, tail, nullptr};
    tail->next = p106;
    tail = p106;

    Node* tempHead = head;
    head = head->next;
    head->prev = nullptr;
    delete tempHead;

    Node* temp104 = n4;
    temp104->prev->next = temp104->next;
    temp104->next->prev = temp104->prev;
    delete temp104;

    Node* tempTail = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete tempTail;

    display(head);
    return 0;
}
