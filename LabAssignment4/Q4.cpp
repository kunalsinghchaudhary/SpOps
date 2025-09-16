#include <iostream>
using namespace std;

int main() {
    char s[100];
    cout << "Enter characters (space-separated, end with newline): ";
    cin.getline(s, 100);

    int freq[256];
    for (int i = 0; i < 256; i++) freq[i] = 0;

    char q[100];
    int front = 0, rear = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (ch == ' ') continue; 

        freq[(unsigned char)ch]++;
        q[rear++] = ch;

        while (front < rear && freq[(unsigned char)q[front]] > 1) {
            front++;
        }

        if (front == rear) {
            cout << "-1 ";
        } else {
            cout << q[front] << " ";
        }
    }

    return 0;
}
