// Lab 10 - Scenario 1: Browser Back button (stack using linked list)
#include <iostream>
#include <string>
using namespace std;

struct Node{
    string page;
    Node* next;
};

Node* top = nullptr;

bool isEmpty(){
    return top == nullptr;
}

void visitPage(string name){
    Node* newNode = new Node;
    newNode->page = name;
    newNode->next = top;
    top = newNode;
    cout << "Visited: " << name << endl;
}

void goBack(){
    // only one page (or none) left, cannot go back
    if (isEmpty() || top->next == nullptr){
        cout << "Cannot go back" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
    cout << "Current page: " << top->page << endl;
}

void currentPage(){
    if (isEmpty())
        cout << "No page opened yet" << endl;
    else
        cout << "Current page: " << top->page << endl;
}

void history(){
    if (isEmpty()){
        cout << "History is empty" << endl;
        return;
    }
    cout << "--- Latest ---" << endl;
    Node* current = top;
    while (current != nullptr){
        cout << current->page << endl;
        current = current->next;
    }
    cout << "--- First ---" << endl;
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
    string name;
    do{
        cout << "\n1. Visit page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Current page" << endl;
        cout << "4. History" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:
            cout << "Enter page name: ";
            cin >> name;
            visitPage(name);
            break;
        case 2:
            goBack();
            break;
        case 3:
            currentPage();
            break;
        case 4:
            history();
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
