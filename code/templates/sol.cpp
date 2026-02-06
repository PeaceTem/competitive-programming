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
    for(int i=2; i<MAXN; i++){
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


void solve(){
    cout << "Working!" << endl;
    cout << binpowll(2LL, 3LL) << endl;
    cout << binpow(2, 3) << endl;
    cout << lcm(6, 3) << endl;
    
    cout << lcmll(6LL, 3) << endl;
    cout << gcd(6, 3) << endl;
    cout << gcdll(6LL, 3) << endl;
    cout << modpow(2, 5, 1e9 + 7) << endl;
    cout << modpowll(2, 5, 1e9 + 7) << endl;

    vector<int> p = sieve(1000);

    cout << p[0] << endl;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
  
    int t = 1; 
    // cin >> t;
    while(t-->0){
        solve();
    }
    return 0;
}
