#include <iostream>
using namespace std;
#define N 100

void traverse(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}
int insert(int arr[], int &size, int element, int position) 
{
    if (size == N) 
    {
        cout << "Array is full, cannot insert." << '\n';
        return -1;
    }
    if (position < 0 || position > size) 
    {
        cout << "Invalid position!" << '\n';
        return -1;
    }
    for (int i = size; i > position; i--) 
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    return 0;
}
int remove(int arr[], int &size, int position) 
{
    if (position < 0 || position >= size) 
    {
        cout << "Invalid position!" << '\n';
        return -1;
    }
    for (int i = position; i < size - 1; i++) 
    {
        arr[i] = arr[i + 1];
    }
    size--;
    return 0;
}
int search(int arr[], int size, int element) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == element) 
        {
            return i;
        }
    }
    return -1;
}
void sortArray(int arr[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() 
{
    int arr[N];
    int size = 0, choice;

    do {
        cout<< "Choose operation:\n"
            << "1. Traverse\n"
            << "2. Insert\n"
            << "3. Remove\n"
            << "4. Search\n"
            << "5. Sort\n"
            << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: 
            {  
                traverse(arr, size);
                break;
            }
            case 2: 
            {  
                int element, position;
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position: ";
                cin >> position;
                insert(arr, size, element, position);
                traverse(arr, size);
                break;
            }
            case 3: 
            {  
                int position;
                cout << "Enter position to remove: ";
                cin >> position;
                remove(arr, size, position);
                traverse(arr, size);
                break;
            }
            case 4: 
            {  
                int element;
                cout << "Enter element to search: ";
                cin >> element;
                int index = search(arr, size, element);
                if (index != -1)
                    cout << "Element " << element << " found at index: " << index << '\n';
                else
                    cout << "Element " << element << " not found!" << '\n';
                break;
            }
            case 5: 
            {  
                sortArray(arr, size);
                cout << "Array after sorting: ";
                traverse(arr, size);
                break;
            }
            case 6: 
            {
                cout << "Exiting...\n";
                break;
            }
            default: 
            {
                cout << "Invalid choice! Please try again.\n";
            }
        }
    } while (choice != 6);
    return 0;
}
