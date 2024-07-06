#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pNext;
};

struct LinkedList {
    Node *pHead, *pTail;
};

Node* CreateNode(int init_data) {
    Node* node = new Node;
    node->data = init_data;
    node->pNext = NULL;
    return node;
}

void CreateList(LinkedList &list) {
    list.pHead = list.pTail = NULL;
}

void InputList(LinkedList& list, Node* node) {
    if (list.pHead == NULL) {
        list.pHead = node;
        list.pTail = node;
    } else {
        list.pTail->pNext = node;
        list.pTail = node;
    }
}

void DisplayList(const LinkedList& list) {
    Node* temp = list.pHead;
    if (temp == NULL) {
        cout << "Empty List" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->pNext;
    }
    cout << endl;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int FindIndex(const LinkedList& list) {
    int total_primes = 0;
    Node* temp = list.pHead;
    while (temp != NULL) {
        if (isPrime(temp->data)) {
            total_primes++;
        }
        temp = temp->pNext;
    }

    int left_primes = 0;
    temp = list.pHead;
    int index = 0;
    int last_valid_index = -1;
    while (temp != NULL) {
        if (isPrime(temp->data)) {
            left_primes++;
        }
        if (left_primes == total_primes - left_primes) {
            last_valid_index = index;
        }
        index++;
        temp = temp->pNext;
    }

    return last_valid_index;
}

void DeletePrimes(LinkedList& list, int index) {
    Node* temp = list.pHead;
    Node* prev = NULL;
    int current_index = 0;

    while (temp != NULL && current_index <= index) {
        prev = temp;
        temp = temp->pNext;
        current_index++;
    }

    while (temp != NULL) {
        if (isPrime(temp->data)) {
            Node* to_delete = temp;
            if (prev) {
                prev->pNext = temp->pNext;
            }
            temp = temp->pNext;
            delete to_delete;
        } else {
            prev = temp;
            temp = temp->pNext;
        }
    }

    if (prev) {
        list.pTail = prev;
    } else {
        list.pHead = NULL;
    }
}

int main() {
    LinkedList list;
    CreateList(list);
    int data;
    while (cin >> data) {
        if (data == 0) break;
        Node* node = CreateNode(data);
        InputList(list, node);
    }

    if (list.pHead == NULL) {
        cout << "Empty List" << endl;
        return 0;
    }

    DisplayList(list);

    int index = FindIndex(list);
    if (index == -1) {
        cout << "not found" << endl;
    } else {
        cout << index << endl;
        DeletePrimes(list, index);
        DisplayList(list);
    }
    return 0;
}

