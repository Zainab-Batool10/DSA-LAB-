
#include <iostream>
using namespace std;

#define SIZE 4

int queue[SIZE];
int front = -1, rear = -1, count = 0;

void enqueue(int value)
{
    if (count == SIZE)
    {
        cout << "Queue is full! Cannot insert "
             << value << endl;
        return;
    }

    if (count == 0)
    {
        front = 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    count++;

    cout << "Inserted: " << value << endl;
}

void dequeue()
{
    if (count == 0)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Removed: " << queue[front] << endl;

    if (count == 1)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }

    count--;
}

void display()
{
    cout << "Queue: ";

    for (int i = 0; i < count; i++)
    {
        cout << queue[(front + i) % SIZE] << " ";
    }

    cout << endl;
}

void showStatus(int step)
{
    cout << "\nStep " << step << endl;
    cout << "Front = " << front << endl;
    cout << "Rear = " << rear << endl;
    cout << "Count = " << count << endl;

    display();
}

int main()
{
    enqueue(101);
    showStatus(1);

    enqueue(102);
    showStatus(2);

    enqueue(103);
    showStatus(3);

    enqueue(104);
    showStatus(4);

    enqueue(105);
    showStatus(5);

    dequeue();
    showStatus(6);

    dequeue();
    showStatus(7);

    enqueue(105);
    showStatus(8);

    enqueue(106);
    showStatus(9);

    return 0;
}
