

#include <bits/stdc++.h>
using namespace std;

// Step 1: Simple sieve to generate primes up to sqrt(R)
vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= limit; i++)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

// Step 2: Segmented sieve for [L, R]
void segmentedSieve(long long L, long long R) {
    long long limit = sqrt(R);
    vector<int> primes = simpleSieve(limit);

    vector<bool> isPrime(R - L + 1, true);

    // Special case: 1 is not prime
    if (L == 1) isPrime[0] = false;

    // Step 3: Mark multiples of small primes
    for (long long p : primes) {
        long long start = max(p * p, ((L + p - 1) / p) * p);

        for (long long x = start; x <= R; x += p)
            isPrime[x - L] = false;
    }

    // Step 4: Print primes
    for (long long i = 0; i <= R - L; i++) {
        if (isPrime[i])
            cout << (L + i) << " ";
    }
    cout << endl;
}

int main() {
    long long L = 10, R = 50;
    segmentedSieve(L, R);
}


const int N = 5;
vector<vector<ll>> mul(const vector<vector<ll>> &A, const vector<vector<ll>> &B, ll mod) {
    vector<vector<ll>> C(N, vector<ll>(N, 0));
    for(int i = 0; i < N; i++)
        for(int k = 0; k < N; k++)
            if(A[i][k])
                for(int j = 0; j < N; j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll e, ll mod) {
    vector<vector<ll>> R(N, vector<ll>(N, 0));
    for(int i = 0; i < N; i++) R[i][i] = 1;

    while(e) {
        if(e & 1) R = mul(R, A, mod);
        A = mul(A, A, mod);
        e >>= 1;
    }
    return R;
}

// rows defining the updates
T[0] = {1,0,0,1,0}; // a0' = a0 + s
T[1] = {1,1,0,1,0}; // a1' = a0 + a1 + s
T[2] = {1,1,1,1,0}; // a2' = sum + s
T[3] = {0,0,0,1,1}; // s' = s + 1
T[4] = {0,0,0,0,1}; // constant

vector<vector<ll>> Tk = power(T, k, m);

vector<ll> X = {a[0] % m, a[1] % m, a[2] % m, 1, 1};

vector<ll> R(5, 0);
for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
        R[i] = (R[i] + Tk[i][j] * X[j]) % m;

for(int i = 0; i < n; i++)
    cout << R[i] << " ";
cout << "\n";