#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void FindNearestPrimes(int* arr, int n, int center, int left, int right, int& closestPrime, int& minDistance) {
    if (left < 0 && right >= n) {
        return;
    }

    if (left >= 0 && IsPrime(*(arr+left))) {
        int distance = center - left;
        if (distance < minDistance) {
            closestPrime = *(arr+left);
            minDistance = distance;
        } else if (distance == minDistance) {
            cout << *(arr+left) << " ";
        }
    }

    if (right < n && IsPrime(*(arr+right)) && right != left) {
        int distance = right - center;
        if (distance < minDistance) {
            closestPrime = *(arr+right);
            minDistance = distance;
        } else if (distance == minDistance) {
            cout << *(arr+right) << " ";
        }
    }

    FindNearestPrimes(arr, n, center, left - 1, right + 1, closestPrime, minDistance);
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> *(arr+i);
    }

    int center = n / 2;
    int closestPrime = -1;
    int minDistance = n;

    FindNearestPrimes(arr, n, center, center, center, closestPrime, minDistance);

    if (closestPrime != -1) {
        cout << closestPrime << " ";
    } else {
        cout << "No prime number found" << endl;
    }

    delete[] arr;
    system("pause");
    return 0;
}
