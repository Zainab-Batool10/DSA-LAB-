#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

void display(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data;
        if(temp->next != nullptr){
            cout << "<->";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* n1 = new Node{10, nullptr, nullptr};
    Node* n2 = new Node{20, n1, nullptr};
    n1->next = n2;
    Node* n3 = new Node{30, n2, nullptr};
    n2->next = n3;
    Node* n4 = new Node{40, n3, nullptr};
    n3->next = n4;
    Node* n5 = new Node{50, n4, nullptr};
    n4->next = n5;

    Node* head = n1;
    Node* tail = n5;

    Node* newStart = new Node{5, nullptr, head};
    head->prev = newStart;
    head = newStart;

    Node* newMid = new Node{25, n2, n2->next};
    n2->next->prev = newMid;
    n2->next = newMid;

    Node* newEnd = new Node{60, tail, nullptr};
    tail->next = newEnd;
    tail = newEnd;

    cout << "Final List (Task 1):";
    display(head);

    return 0;
}
