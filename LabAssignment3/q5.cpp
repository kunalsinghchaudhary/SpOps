#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> s;

    for (char c : expr) {
        if (isdigit(c)) {
            s.push(c - '0');  
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    string postfix;
    cin >> postfix;
    cout << evaluatePostfix(postfix);
    return 0;
}
