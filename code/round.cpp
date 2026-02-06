#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define lb lower_bound
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
// #define MOD 1000000007
#define INF 1000000000000000000LL
#define MAXN 1000005
#define ld long double
#define eps 1e-9
// #define bit(n,b) (((n) >> (b)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define bitcountll(n) __builtin_popcountll(n)

// #define gcd(a,b) __gcd(a,b)   // DO NOT USE, CONFLICTS WITH FUNCTION

// ============================================================
// STRING SPLIT
// ============================================================

vector<string> split(const string &s) {
    vector<string> res;
    stringstream ss(s);
    string token;
    while (ss >> token) res.push_back(token);
    return res;
}

vector<string> split(const string &s, char delim) {
    vector<string> res;
    string token;
    stringstream ss(s);
    while (getline(ss, token, delim)) res.push_back(token);
    return res;
}

string join(const vector<string> &v, const string &sep) {
    string out = "";
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) out += sep;
        out += v[i];
    }
    return out;
}

// ============================================================
// MATH UTILITIES
// ============================================================

// Count divisors
long long count_divisors(long long n) {
    long long ans = 1;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) n /= p, cnt++;
            ans *= (cnt + 1);
        }
    }
    if (n > 1) ans *= 2;
    return ans;
}

// Sum of divisors
long long sum_divisors(long long n) {
    long long ans = 1;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            long long current = 1, term = 1;
            while (n % p == 0) {
                n /= p;
                term *= p;
                current += term;
            }
            ans *= current;
        }
    }
    if (n > 1) ans *= (1 + n);
    return ans;
}

// Prime factorization
vector<pair<long long,int>> prime_fact(long long n) {
    vector<pair<long long,int>> factors;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) n /= p, cnt++;
            factors.push_back({p, cnt});
        }
    }
    if (n > 1) factors.push_back({n,1});
    return factors;
}

// Sieve
vector<int> sieve() {
    vector<bool> is_prime(MAXN, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAXN; j += i)
                is_prime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i < MAXN; i++)
        if (is_prime[i]) primes.pb(i);
    return primes;
}

// Binary exponentiation modulo
ll modpow(ll a, ll b, ll mod) {
    ull res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Integer exponentiation
ll binpow(ll a, ll b) {
    ull res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

// ============================================================
// EXTENDED GCD + MODULAR INVERSE
// ============================================================

long long egcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

long long modinv(long long a, long long m) {
    long long x, y;
    long long g = egcd(a, m, x, y);
    if (g != 1) return -1; // inverse doesn't exist
    x %= m;
    if (x < 0) x += m;
    return x;
}

// ============================================================
// GCD / LCM
// ============================================================

long long gcdll(long long a, long long b) {
    return b == 0 ? a : gcdll(b, a % b);
}

long long lcmll(long long a, long long b) {
    return (a / gcdll(a, b)) * b;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    int n; cin>> n;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t-- > 0) {
        solve();
    }
}