#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

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

void solve() {
    int l,r; cin>>l>>r;
    if(l==r){
        if(1==l) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    // else if(gcd(l,r) >= 1){
    //     if(gcd(l,r) > 1){
    //         vector<bool> primes = sieveOfEratosthenes(gcd(l,r));
    //         if(primes[gcd(l,r)]){
    //             cout << r-l << '\n';
    //         }
    //         else cout << 0 << '\n';
    //     }


    //     else{
    //     cout << r-l << '\n';
    //     }
    else {
        cout << r-l << '\n';
    }
    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }

}