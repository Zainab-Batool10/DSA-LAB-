#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
int main()
{
    Node* head;
    Node* temp;
    Node* deleteNode;

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
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    temp = head;
    temp = temp->next;

    // Node to delete
    deleteNode = temp;
    n1->next = deleteNode->next;
    delete deleteNode;

    // Display after deletion
    cout << "\nAfter deletion: ";
    temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
