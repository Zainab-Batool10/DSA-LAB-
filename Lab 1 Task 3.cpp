#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    int *ptr = &number;

    cout << "Before changing: " << number << endl;
    *ptr = *ptr + 100;
    cout << "After changing: " << number << endl;

    return 0;
}
