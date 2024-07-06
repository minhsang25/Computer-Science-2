#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        *(matrix + i) = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> *(*(matrix + i) +j);
        }
    }

    bool* adjacent_to_all = new bool[n];
    for (int i = 0; i < n; i++) {
        *(adjacent_to_all + i) = true;
        for (int j = 0; j < n; j++) {
            if (i!= j && *(*(matrix + i) +j) == 0) {
                *(adjacent_to_all + i) = false;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (*(adjacent_to_all + i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        delete[] *(matrix + i);
    }
    delete[] matrix;
    delete[] adjacent_to_all;
    return 0;
}
