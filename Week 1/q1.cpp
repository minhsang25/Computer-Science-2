#include <iostream>
using namespace std;

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main(){
    int a,b;
    cout<<"Enter two numbers: "<<endl;
    cin>>a>>b;
    swap(&a, &b);
    cout<<"After swapping: "<<a<<" "<<b<<endl;
    system("pause");
    return 0;
}