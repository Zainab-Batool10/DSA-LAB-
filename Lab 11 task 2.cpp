#include <iostream>
using namespace std;
 
struct Node {
    int data;       
    Node* next;     
};
 
Node* front = NULL; 
Node* rear = NULL;  
 
bool isEmpty() {
    return front == NULL;
}

void enqueue(int value) {
    Node* newNode = new Node; 
    newNode->data = value;
    newNode->next = NULL;
 
    if (isEmpty()) {           
        front = newNode;
        rear = newNode;
    } else {                   
        rear->next = newNode;  
        rear = newNode;        
    }
    cout << value << " added to the queue." << endl;
}
 
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Nothing to remove." << endl;
        return;
    }
    Node* temp = front;            // 1. remember the first node
    cout << temp->data << " removed from the queue." << endl;
    front = front->next;           // 2. move front to the next node
    if (front == NULL) {           // 3. queue became empty
        rear = NULL;
    }
    delete temp;                   // 4. free the memory
}
 
void peek() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }
    cout << "Front element: " << front->data << endl;
}
 
void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }
    cout << "FRONT -> ";
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout << "(REAR points to " << rear->data << ")" << endl;
}

void countNode(){
	Node* temp = front;
	int count = 1;
	while(temp->next != nullptr){
		temp = temp->next;
		count++;
	}
	cout<<"Count: "<<count<<endl;
}

void displayRear() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }
    cout << "Value at rear: " << rear->data << endl;
}

void clearQueue(){
	Node* temp = front;
	Node* del;
	while(temp->next != nullptr){
		del = front;
		front = front->next;
	delete del;
	}
	cout<<rear->data<<endl;
}
	

 
int main() {
    int choice, value;
 
    do {
        cout << "\n*** Queue Using Linked List ***" << endl;
        cout << "1. Enqueue  2. Dequeue  3. Peek 4.Node Count  5. Display 6. Display Rear 7. Clear Queue  8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
 
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                countNode();
                break;
            case 5:
                display();
                break;
            case 6:
                displayRear();
                break;
            case 7:
                clearQueue();
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 8);
 
    return 0;
}
