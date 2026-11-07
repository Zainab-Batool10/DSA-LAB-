#include <iostream>
using namespace std;

int main() {
    int arr[2][2][2];
    int evenCount = 0, oddCount = 0;

    cout << "Enter 8 elements for a 2x2x2 3D array:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                cout << "Element [" << i << "][" << j << "][" << k << "]: ";
                cin >> arr[i][j][k];
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (arr[i][j][k] % 2 == 0)
                    evenCount++;
                else
                    oddCount++;
            }
        }
    }

    cout << "\nTotal even elements: " << evenCount << endl;
    cout << "Total odd elements: " << oddCount << endl;

    return 0;
}
