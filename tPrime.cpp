#include <bits/stdc++.h>

using namespace std;


// Function to generate primes using Sieve of Eratosthenes
vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true); // Initialize all numbers as prime
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime numbers

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            // Mark multiples of i as non-prime
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}


int main(){

    vector<bool> primes = sieveOfEratosthenes(1000000);

    int n; cin >> n;

    vector<long long> x(n);

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }


    long long square_root;
    for(int i = 0; i < n; i++){
        square_root = sqrt(x[i]);

        if(square_root * square_root == x[i]){
            if(primes[square_root]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "NO"<< endl;

    }
}