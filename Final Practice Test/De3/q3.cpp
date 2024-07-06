
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = topNode;
        topNode = temp;
    }

    void pop() {
        if (topNode == nullptr) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        if (topNode == nullptr) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    void reversePrimes() {
        Stack primes;    
        Stack tempStack;   

        while (!isEmpty()) {
            int x = top();
            pop();
            if (isPrime(x)) {
                primes.push(x);
            }
            tempStack.push(x);
        }

        while (!tempStack.isEmpty()) {
            int x = tempStack.top();
            tempStack.pop();
            if (isPrime(x)) {
                push(primes.top());
                primes.pop();
            } else {
                push(x);
            }
        }
    }

    void printStack() {
        Stack temp;
        while (!isEmpty()) {
            cout << top() << " ";
            temp.push(top());
            pop();
        }
        while (!temp.isEmpty()) {
            push(temp.top());
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int x;
    while (cin >> x) {
        if (x == 0) break;
        s.push(x);
    }
    
    s.printStack(); 

    s.reversePrimes(); 
    s.printStack();    
    return 0;
}

