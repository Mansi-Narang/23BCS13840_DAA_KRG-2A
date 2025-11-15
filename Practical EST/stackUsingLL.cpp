#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class Stack {
private:
    Node* topNode;
    int count;

public:
    Stack() {
        topNode = nullptr;
        count = 0;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    int pop() {
        if (isEmpty()) return -1;
        int val = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
        return val;
    }

    int peek() {
        if (isEmpty()) return -1;
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    int size() {
        return count;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.peek() << endl;
    cout << st.pop() << endl;
    cout << st.size() << endl;
    cout << st.isEmpty() << endl;

    return 0;
}
