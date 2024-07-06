#include <iostream>
using namespace std; 

bool CheckSquare(int** matrix, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (*(*(matrix+i)+j) == 1 && *(*(matrix+i)+j+1) == 1 && *(*(matrix+i +1)+j) == 1 && *(*(matrix+i+1)+j+1) == 1) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    int** matrix = new int*[n];
    for (int i=0; i<n; i++){
        matrix[i] = new int[n];
        for (int j=0; j<n; j++){
            cin >> *(*(matrix+i)+j);
        }
    }
    if (CheckSquare(matrix, n)) {
        cout << "yes"<<endl;
    } else {
        cout << "no"<<endl;
    }
    for (int i=0; i<n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
