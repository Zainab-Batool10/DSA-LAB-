#include <iostream>
using namespace std;

int main() {
    int num = 40;
    int *ptr = &num;
    int **pp = &ptr;

    cout << "Original value: " << num << endl;
    cout << "Using pointer: " << *ptr << endl;
    cout << "Using double pointer: " << **pp << endl;

    **pp = 150;

    cout << "After modifying using **pp: " << num << endl;

    return 0;
}
