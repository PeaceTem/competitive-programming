#include <bits/stdc++.h>

using namespace std;

vector<bool> sieve(int n){
    vector<bool> primes(n+1, true);
    primes[0]=primes[1]=false;
    for(int i=2;i*i<n;i++){
        if(primes[i]){
            for(int j=i*i;j<=n;j+=i) primes[j]=false;
        }
    }

    return primes;
}

int main(){
    vector<bool> primes = sieve(2000000);
    long long total = 0LL;
    for(int i=0;i<=2000000;i++){
        if(primes[i]) total += i;
    }

    cout << total << '\n';
}