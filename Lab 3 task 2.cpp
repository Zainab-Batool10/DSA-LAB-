#include <iostream>
using namespace std;

int main() {
    int matrix[3][3];
    int positive = 0, negative = 0, zero = 0;

    cout << "Enter 9 elements for a 3x3 matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] > 0)
                positive++;
            else if (matrix[i][j] < 0)
                negative++;
            else
                zero++;
        }
    }

    cout << "\nPositive elements: " << positive << endl;
    cout << "Negative elements: " << negative << endl;
    cout << "Zero elements: " << zero << endl;

    return 0;
}
