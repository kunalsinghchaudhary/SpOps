#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == MAX - 1; }

    void enqueue(int x) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return val;
    }

    int size() { return isEmpty() ? 0 : (rear - front + 1); }

    void display() {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void interleave() {
    if (isEmpty()) return;
    int n = size();
    int half = n / 2;
    int firstHalf[MAX];

    for (int i = 0; i < half; i++)
        firstHalf[i] = dequeue();

    int result[MAX];
    int idx = 0;

    for (int i = 0; i < half; i++) {
        result[idx++] = firstHalf[i];
        result[idx++] = dequeue();
    }

    front = 0; rear = n - 1;
    for (int i = 0; i < n; i++) arr[i] = result[i];
}

};

int main() {
    Queue q;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.enqueue(val);
    }

    q.interleave();

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}
