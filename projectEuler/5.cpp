#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; 
}


int main(){
    int l=1;
    for(int i=2; i<21;i++){
        if(i>20) break;
        l = lcm(l,i);
    }
    cout<<l<<endl;
}