#include <iostream>
using namespace std;

#define SIZE 10
int items[SIZE];
int front = 0;
int rear = -1;

bool isEmpty() {
	return front > rear; 
}
bool isFull()  { 
	return rear == SIZE - 1; 
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is FULL! Cannot add " << value << endl;
        return;
    }
    items[++rear] = value;
}

int dequeue() {
    int value = items[front];
    front++;
    if (front > rear) {     
        front = 0;
        rear = -1;
    }
    return value;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }
    cout << "FRONT -> ";
    for (int i = front; i <= rear; i++)
        cout << items[i] << " ";
    cout << "<- REAR" << endl;
}

int stackArr[SIZE];
int top = -1;

void push(int value) { stackArr[++top] = value; }
int  pop()           { return stackArr[top--]; }
bool stackEmpty()    { return top == -1; }

void reverseQueue() {
    while (!isEmpty())
        push(dequeue());
    while (!stackEmpty())
        enqueue(pop());
}

int main() {
    int input[] = {10, 20, 30, 40};
    for (int i = 0; i < 4; i++)
        enqueue(input[i]);

    cout << "Before reversing: ";
    display();

    reverseQueue();

    cout << "After reversing:  ";
    display();
    return 0;
}
