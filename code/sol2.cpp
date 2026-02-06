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
#define pii pair<int, int>
#define vii vector<pii>
// #define MOD 1000000007
#define INF 1000000000000000000
#define MAXN 1000005
#define ld long double
#define eps 1e-9

ll modpowll(ll a, ll b, ll mod) {
    ll res = 1;
    a = a % mod;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>=1;
    }

    return res;
}

int modpow(int a, int b, int mod) {
    ll res = 1;
    a = a % mod;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>=1;
    }

    return res;
}

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return (a / gcd(a, b)) * b;
}

ll lcmll(ll a, ll b){
    return (a / gcd(a, b)) * b;
}

ll gcdll(ll a, ll b){
    return b == 0 ? a : gcdll(b, a % b);
}

vector<int> sieve(int n){
    vector<bool> is_prime(n, true);
    is_prime[1] = false;
    is_prime[0] = false;
    for(int i=2; i*i < n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<n; j+=i){
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for(int i=2; i<n; i++){
        if(is_prime[i]) primes.pb(i);
    }

    return primes;
}


int binpow(int a, int b) {
    int res = 1;
    while(b){
        if(b & 1) res = res * a;
        a *= a;
        b >>=1;
    }

    return res;
}


ll binpowll(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b & 1) res = res * a;
        a *= a;
        b >>=1;
    }

    return res;
}

ll binmodll(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b & 1) res = res * a;
        a *= a;
        b >>=1;
    }

    return res;
}

bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

ll sumDivisors(ll n) {
    ll sum = 0;
    for (ll i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n/i) sum += n/i;
        }
    }
    return sum;
}


void solve(){
    int x, y; cin >> x >> y;

    int p = x, q = y;
    if(p < q) swap(p, q);
    int end_iter = -1;
    for(int i = 0; i <= 30; i++){

        if((p & (1 << i)) && (q & (1 << i))){
            int iter = i - 1;
            while(iter >= 0 && iter > end_iter){
                if((p & (1 << iter)) == 0 && (q & (1 << iter)) == 0){
                    p |= (1 << iter);
                }
                iter--;
            }
            p ^= (1 << i);
            end_iter = i;
        }
    }
    if(x < y) swap(p, q);
    cout << p << " " << q << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
  
    int t = 1; 
    cin >> t;
    while(t-->0){
        solve();
    }
    return 0;
}
