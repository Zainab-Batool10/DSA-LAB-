// Lab 9 - Task 3: Array stack (MAX = 5) with overflow, underflow and search
#include <iostream>
using namespace std;

const int MAX = 5;
int stk[MAX];
int top = -1;

bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top == MAX - 1;
}

void push(int x){
    if (isFull()){
        cout << "Stack overflow: cannot push " << x << endl;
    }
    else{
        top++;
        stk[top] = x;
        cout << x << " pushed." << endl;
    }
}

void pop(){
    if (isEmpty()){
        cout << "Stack underflow: nothing to pop" << endl;
    }
    else{
        cout << "Popped: " << stk[top] << endl;
        top--;
    }
}

// returns how many steps from the top (1 = top), -1 if not found
int search(int x){
    for (int i = top; i >= 0; i--){
        if (stk[i] == x)
            return top - i + 1;
    }
    return -1;
}

int main(){
    int value;

    // Push five integers
    cout << "Enter 5 integers:" << endl;
    for (int i = 0; i < MAX; i++){
        cout << "Element " << i + 1 << ": ";
        cin >> value;
        push(value);
    }

    // Sixth push -> overflow
    cout << "\nTry to push a sixth integer: ";
    cin >> value;
    push(value);

    // Search (one value present, one absent)
    int x;
    cout << "\nEnter a value that is in the stack: ";
    cin >> x;
    int result = search(x);
    if (result != -1)
        cout << x << " is " << result << " step(s) from the top" << endl;
    else
        cout << x << " not found (-1)" << endl;

    cout << "Enter a value that is not in the stack: ";
    cin >> x;
    result = search(x);
    if (result != -1)
        cout << x << " is " << result << " step(s) from the top" << endl;
    else
        cout << x << " not found (-1)" << endl;

    // Pop all items
    cout << "\nPopping all items:" << endl;
    for (int i = 0; i < MAX; i++){
        pop();
    }

    // One more pop -> underflow
    pop();

    return 0;
}
