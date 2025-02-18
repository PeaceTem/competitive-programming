#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> fibo(10000, 0); fibo[1] = 1; fibo[2]=2; int total = 2;
    for(int i=3; i<10000; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
        if(fibo[i]> 4000000) break;
        if(fibo[i] % 2 == 0) total += fibo[i];
    }
    cout << total;
}