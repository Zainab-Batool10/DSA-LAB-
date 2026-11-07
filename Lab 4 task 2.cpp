//Task 2: memory allocation for single character
//store -> print -> deallocate space -> point to null
#include <iostream>
using namespace std;

int main() {
    char *ch = new char;
    cout << "Enter a character: ";
    cin >> *ch;
    cout << "Stored character: " << *ch << endl;
    delete ch;
    ch = nullptr;
    return 0;
}
