#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (isupper(ch)) {
        char lower = tolower(ch);
        cout << "Lowercase character: " << lower << endl;
    } else {
        cout << "The character is not uppercase." << endl;
    }

    return 0;
}