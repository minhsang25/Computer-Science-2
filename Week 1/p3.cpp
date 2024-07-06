
bool is_Prime(int a) {
    if (a <= 1) return false;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

void PrimeArrayInput(int *a, int &n){
    cin >> n;

    int cnt = 0;
    int num = 2; 
    while (cnt < n) {
        if (is_Prime(num)) {
            a[cnt] = num;
            cnt++;
        }
        num++;
    }
}
bool check_y(int t, int y){
    while(t > 0){
        if(t % 10 == y) return true;
        t /= 10;
    }
    return false;
}

int NOEContainsY(int *a, int n, int y){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(check_y(a[i], y)){
            cnt++;
        }
    }
    return cnt;
}
