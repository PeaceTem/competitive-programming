#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


vector<bool> sieve(int n){
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<n;i++){
        if(isPrime[i]){
            for(int j=i*i; j<n+1; j+=i){
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}


int main(){
    ll n=600851475143;
    vector<bool> primes = sieve(sqrt(n));
    int maxPrime = 1;
    for(int i=3;i<=sqrt(n);i+=2){
        if(primes[i]){
            if(n%i==0) maxPrime = i;
        }
    }
    cout << maxPrime;
}