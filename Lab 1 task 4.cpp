#include <iostream>
using namespace std;

void swapValues(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << endl;
    swapValues(&num1, &num2);
    cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << endl;
    return 0;
}
