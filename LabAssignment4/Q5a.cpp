#include <iostream>
using namespace std;

class StackTwoQ {
    int q1[100], q2[100];
    int front1, rear1, front2, rear2;
    int size;

public:
    StackTwoQ() {
        front1 = rear1 = front2 = rear2 = 0;
        size = 0;
    }

    void push(int x) {
        q2[rear2++] = x;

        while (front1 != rear1) {
            q2[rear2++] = q1[front1++];
        }

        swap(q1, q2);
        swap(front1, front2);
        swap(rear1, rear2);

        size++;
    }

    int pop() {
        if (front1 == rear1) {
            cout << "Stack is empty\n";
            return -1;
        }
        size--;
        return q1[front1++];
    }

    int top() {
        if (front1 == rear1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1[front1];
    }

    bool empty() {
        return (front1 == rear1);
    }
};

int main() {
    StackTwoQ st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << endl; 
    cout << "Pop: " << st.pop() << endl; 
    cout << "Pop: " << st.pop() << endl; 
    cout << "Top: " << st.top() << endl; 
    return 0;
}
