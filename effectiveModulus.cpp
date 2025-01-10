#include <bits/stdc++.h>

using namespace std;

long long exponent(long long a, long long n){
    if(n == 0){
        return 1;
    } else if(n % 2 == 0){
        return pow(exponent(a, n / 2), 2);
    } 
    return a * pow(exponent(a, n / 2), 2);
}


int modulo(long long a, long long n, short m){
    if(n == 0){
        return 1;
    } else if(n % 2 == 0){
        return pow(exponent(a, n / 2), 2);
    } 
    return a * pow(exponent(a, n / 2), 2);
}


int main(){
    long long a, n, m;
    cin >> a >> n >> m;
    cout << modulo(a, n, m) << endl;
    return 0;
}