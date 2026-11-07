// Lab 10 - Scenario 4: Decimal to Binary converter (stack using linked list)
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top = nullptr;

bool isEmpty(){
    return top == nullptr;
}

void push(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop(){
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

int main(){
    int number;
    cout << "Enter number: ";
    cin >> number;

    cout << "Binary: ";

    // Handle input 0
    if (number == 0){
        cout << 0 << endl;
        return 0;
    }

    // Divide by 2 and push each remainder
    while (number > 0){
        push(number % 2);
        number = number / 2;
    }

    // Pop all remainders
    while (!isEmpty()){
        cout << pop();
    }
    cout << endl;

    return 0;
}
