
#include <iostream>
using namespace std;

#define SIZE 6

int queue[SIZE];
int front = -1, rear = -1;

// Function to issue token (Enqueue)
void issueToken()
{
    if (rear == SIZE - 1)
    {
        cout << "Waiting room is full!" << endl;
    }
    else
    {
        int token;
        cout << "Enter token number: ";
        cin >> token;

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = token;

        cout << "Token issued successfully!" << endl;
    }
}

// Function to serve customer (Dequeue)
void serveCustomer()
{
    if (front == -1 || front > rear)
    {
        cout << "No customer is waiting!" << endl;
    }
    else
    {
        cout << "Customer with token "
             << queue[front] << " is being served." << endl;

        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

// Function to show waiting customers
void showCustomers()
{
    if (front == -1)
    {
        cout << "No customers are waiting." << endl;
    }
    else
    {
        cout << "Waiting customers: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n===== BANK TOKEN SYSTEM =====" << endl;
        cout << "1. Issue Token" << endl;
        cout << "2. Serve Customer" << endl;
        cout << "3. Show Waiting Customers" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                issueToken();
                break;

            case 2:
                serveCustomer();
                break;

            case 3:
                showCustomers();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
