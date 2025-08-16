#include <iostream>
using namespace std;

int main() {
    int ch, arr[50], size = 0, pos, ele;

    cout << "---MENU---" << endl;
    cout << "1.CREATE" << endl;
    cout << "2.DISPLAY" << endl;
    cout << "3.INSERT" << endl;
    cout << "4.DELETE" << endl;
    cout << "5.LINEAR SEARCH" << endl;
    cout << "6.EXIT" << endl;

    cout << "Enter your choice number: ";
    cin >> ch;

    switch (ch) {
        case 1:
            cout << "How many elements do you want to enter? ";
            cin >> size;
            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
            cout << "Array created successfully :)" << endl;
            break;

        case 2:
            if (size == 0) {
                cout << "Array is empty." << endl;
                break;
            }
            cout << "Array elements: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

        case 3:
            if (size == 0) {
                cout << "Array is empty. Create it first." << endl;
                break;
            }
            cout << "Enter element to insert: ";
            cin >> ele;
            cout << "At what position? (1 to " << size + 1 << "): ";
            cin >> pos;
            if (pos < 1 || pos > size + 1) {
                cout << "Invalid position!" << endl;
                break;
            }
            for (int i = size; i >= pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = ele;
            size++;
            cout << "Element inserted successfully :)" << endl;
            break;

        case 4:
            if (size == 0) {
                cout << "Array is empty. Nothing to delete." << endl;
                break;
            }
            cout << "Array contains: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            cout << "Which element to delete (position)? ";
            cin >> pos;
            if (pos < 1 || pos > size) {
                cout << "Invalid position!" << endl;
                break;
            }
            for (int i = pos - 1; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            cout << "Element deleted successfully :)" << endl;
            break;

        case 5:
            if (size == 0) {
                cout << "Array is empty." << endl;
                break;
            }
            cout << "Enter the search element: ";
            cin >> ele;
            {
                int found = 0;
                for (int i = 0; i < size; i++) {
                    if (arr[i] == ele) {
                        cout << "Element found at position " << i + 1 << endl;
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    cout << "Element not found." << endl;
            }
            break;

        case 6:
            cout << "------END------" << endl;
            break;

        default:
            cout << "Enter a valid choice!" << endl;
    }

    return 0;
}
