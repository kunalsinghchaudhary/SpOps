#include <iostream>
using namespace std;

int main() {
    int arr[10][10];
    int rows, cols;
    int i, j;
    int sumrow, sumcol;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter the elements:"<<endl;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    for (i = 0; i < rows; i++) {
        sumrow = 0; // reset for each row
        for (j = 0; j < cols; j++) {
            sumrow = sumrow + arr[i][j];
        }
        cout << "Sum of row " << i << " = " << sumrow << endl;
    }

    for (j = 0; j < cols; j++) {
        sumcol = 0; // reset for each column
        for (i = 0; i < rows; i++) {
            sumcol = sumcol + arr[i][j];
        }
        cout << "Sum of column " << j << " = " << sumcol << endl;
    }

    return 0;
}
