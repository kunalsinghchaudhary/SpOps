#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "How many strings? ";
    cin >> n;
    cin.ignore(); // To clear the newline character

    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, strings[i]);
    }

    sort(strings.begin(), strings.end());

    cout << "Sorted strings:\n";
    for (const string& s : strings) {
        cout << s << endl;
    }

    return 0;
}