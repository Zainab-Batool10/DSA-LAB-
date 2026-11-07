#include <iostream>
using namespace std;

int main() {
    int arr[5] = {12, 7, 18, 25, 30};
    int *ptr = arr;

    int evenCount = 0, oddCount = 0;

    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++) {
        if (*(ptr + i) % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    cout << "Even numbers: " << evenCount << endl;
    cout << "Odd numbers: " << oddCount << endl;

    return 0;
}
