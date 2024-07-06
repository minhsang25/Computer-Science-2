#include <iostream>
#include <iomanip>
using namespace std;

struct arr {
    float max, min, avg;
};

void input(float** &a, int &n, int &m) {
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    a = new float*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new float[m];
    }
    cout << "Enter the matrix: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << endl;
}

void max_col(float** a, int n, int m, arr* &b) {
    b = new arr[m];
    for(int j = 0; j < m; j++) {
        b[j].max = a[0][j];
        b[j].min = a[0][j];
        b[j].avg = 0;
        for(int i = 0; i < n; i++) {
            b[j].max = a[i][j] > b[j].max ? a[i][j] : b[j].max;
            b[j].min = a[i][j] < b[j].min ? a[i][j] : b[j].min;
            b[j].avg += a[i][j];
        }
        b[j].avg /= n; 
        cout << setprecision(2) << "Maximum value of column " << j + 1 << " is " << b[j].max;
        cout << setprecision(2)<< ", minimal value of array is " << b[j].min << " and  average of the column is " << b[j].avg << endl;
    }
}

void output(float** a, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void standardize(float** a, int n, int m, arr* c) {
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            a[i][j] = (a[i][j] - c[j].avg) / (c[j].max - c[j].min);
        }
    }
}

int main() {
    int n, m;
    float** a;
    arr* pro_col = nullptr; 
    
    input(a, n, m);
    max_col(a, n, m, pro_col);
    standardize(a, n, m, pro_col);
    output(a,n,m);

    for(int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    delete[] pro_col;

    system("pause");
    return 0;
}
