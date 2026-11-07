// Lab 10 - Scenario 2: Text editor Undo (stack using linked list)
#include <iostream>
#include <string>
using namespace std;

struct Node{
    string word;
    Node* next;
};

Node* top = nullptr;

bool isEmpty(){
    return top == nullptr;
}

void typeWord(string w){
    Node* newNode = new Node;
    newNode->word = w;
    newNode->next = top;
    top = newNode;
}

void undo(){
    if (isEmpty()){
        cout << "Nothing to undo" << endl;
        return;
    }
    Node* temp = top;
    cout << "Undone: " << temp->word << endl;
    top = top->next;
    delete temp;
}

void lastWord(){
    if (isEmpty())
        cout << "Editor is empty" << endl;
    else
        cout << "Last word: " << top->word << endl;
}

int size(){
    int count = 0;
    Node* current = top;
    while (current != nullptr){
        count++;
        current = current->next;
    }
    return count;
}

void display(){
    if (isEmpty()){
        cout << "Editor is empty" << endl;
        return;
    }
    cout << "--- Last typed ---" << endl;
    Node* current = top;
    while (current != nullptr){
        cout << current->word << endl;
        current = current->next;
    }
    cout << "--- First typed ---" << endl;
}

void clearStack(){
    while (!isEmpty()){
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int main(){
    int choice;
    string w;
    do{
        cout << "\n1. Type word" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Last word" << endl;
        cout << "4. Word count" << endl;
        cout << "5. Display words" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:
            cout << "Enter word: ";
            cin >> w;
            typeWord(w);
            cout << "Word count = " << size() << endl;
            break;
        case 2:
            undo();
            cout << "Word count = " << size() << endl;
            break;
        case 3:
            lastWord();
            break;
        case 4:
            cout << "Word count = " << size() << endl;
            break;
        case 5:
            display();
            break;
        case 0:
            clearStack();
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
    return 0;
}
