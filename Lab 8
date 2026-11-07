// Lab 8 - Searching and Sorting
// Lab Task: Menu-driven program (Selection Sort, Bubble Sort,
// Insertion Sort and Binary Search) on an array of 10 integers.
#include <iostream>
using namespace std;
const int SIZE = 10;

void display(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool isSorted(int arr[], int size){
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

void copyArray(int from[], int to[], int size){
    for (int i = 0; i < size; i++)
        to[i] = from[i];
}

void selectionSort(int arr[], int size){
    int swaps = 0;
    for (int i = 0; i < size - 1; i++){
        int minIndex = i;
        for (int j = i + 1; j < size; j++){
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
    cout << "Swaps performed: " << swaps << endl;
}

void bubbleSort(int arr[], int size){
    int swaps = 0;
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1 - i; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
    cout << "Swaps performed: " << swaps << endl;
}

void insertionSort(int arr[], int size){
    int shifts = 0;
    for (int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
            shifts++;
        }
        arr[j + 1] = key;
    }
    cout << "Shifts performed: " << shifts << endl;
}

int binarySearch(int arr[], int size, int key, int &comparisons){
    int low = 0;
    int high = size - 1;
    comparisons = 0;

    while (low <= high){
        int mid = (low + high) / 2;
        comparisons++;

        if (arr[mid] == key)
            return mid;

        if (key > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    int original[SIZE];
    int arr[SIZE];
    cout << "Enter " << SIZE << " integers:" << endl;
    for (int i = 0; i < SIZE; i++){
        cout << "Element " << i + 1 << ": ";
        cin >> original[i];
    }
    copyArray(original, arr, SIZE);
    int choice;
    do{
        cout << "\n========== MENU =========+" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Binary Search" << endl;
        cout << "5. Display array" << endl;
        cout << "6. Reset array to original (unsorted) values" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:
            selectionSort(arr, SIZE);
            cout << "Array after Selection Sort: ";
            display(arr, SIZE);
            break;
        case 2:
            bubbleSort(arr, SIZE);
            cout << "Array after Bubble Sort: ";
            display(arr, SIZE);
            break;
        case 3:
            insertionSort(arr, SIZE);
            cout << "Array after Insertion Sort: ";
            display(arr, SIZE);
            break;
        case 4:{
            if (!isSorted(arr, SIZE)){
                cout << "Array is not sorted. Sort it first (option 1, 2 or 3), "
                     << "because Binary Search needs a sorted array." << endl;
                break;
            }
            int key, comparisons;
            cout << "Enter value to search: ";
            cin >> key;
            int result = binarySearch(arr, SIZE, key, comparisons);
            if (result != -1)
                cout << "Element found at index " << result;
            else
                cout << "Element not found";
            cout << " (comparisons: " << comparisons << ")" << endl;
            break;
        }
        case 5:
            cout << "Current array: ";
            display(arr, SIZE);
            break;
        case 6:
            copyArray(original, arr, SIZE);
            cout << "Array reset: ";
            display(arr, SIZE);
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
    return 0;
}
