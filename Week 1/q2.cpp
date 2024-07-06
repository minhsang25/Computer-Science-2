#include <iostream>
using namespace std;

void input(int*& a, int& n) {
    cout << "Enter size of an array: ";
    cin >> n;
    a = new int[n];
    cout << "Enter the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int find_max(int* a, int& n) {
    int max= a[0];
    for (int i = 0; i < n; i++) {
        max = (*(a + i) > max) ? *(a + i) : max;
    }
    return max;
}

int main() {
    int n;
    int* a;
    input(a, n);
    cout << "Maximum number in array is: " << find_max(a, n) << endl;
    delete[] a; 
    system("pause");
    return 0;
}
