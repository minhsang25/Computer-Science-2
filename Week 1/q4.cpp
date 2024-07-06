#include <iostream>
using namespace std; 

void input(int** &a, int &n) {
    cout << "Enter the number n: ";
    cin >> n;
    a = new int*[n]; 
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
    }         
    cout<<"Enter the matrix: "<<endl;        
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }                   
    cout<<endl;
}

void max_row(int** a, int n) {
    for(int i = 0; i < n; i++) {
        int max = a[i][0];
        for(int j = 0; j < n; j++) {
            max = a[i][j] > max ? a[i][j] : max;
        }
        cout << "Maximum value of row " << i+1 << " is: " << max << endl;
    }
}

void max_col(int** a, int n) {
    for(int j = 0; j < n; j++) {
        int max = a[0][j];
        for(int i = 0; i < n; i++) {
            max = a[i][j] > max ? a[i][j] : max;
        }
        cout << "Maximum value of column " << j+1 << " is: " << max << endl;
    }
}

bool symmetric(int** a, int n){
    for(int i=1; i<n; i++){
        if(a[i][i-1]!= a[i-1][i]){ 
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    int **a;
    input(a, n);

    max_row(a, n);
    max_col(a, n);

    if(symmetric(a, n)) cout<<"This matrix is symmetric"<<endl;
    else cout<<"This matrix is not symmetric"<<endl; 

    for(int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    system("pause");
    return 0;
}
