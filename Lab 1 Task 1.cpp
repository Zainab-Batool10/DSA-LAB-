#include <iostream>
using namespace std;

int main()
{
    int numbers[5];
    int sum = 0;

    cout << "Enter 5 numbers:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> numbers[i];
        sum += numbers[i];
    }

    double average = static_cast<double>(sum) / 5;

    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;

    return 0;
}
