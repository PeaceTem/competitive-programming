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
#define bit(n, b) (((n) >> (b)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define gcd(a, b) __gcd(a, b)
// #define fileIO freopen("input.txt", "r", stdin); freopen("output.txt", "w

// use assert

struct Mint {
    static const int MOD = 1e9+7;
    int value;

    Mint(long long v = 0) { 
        value = v % MOD;
        if (value < 0) value += MOD;
    }

    Mint operator+(const Mint& other) const { return Mint(value + other.value); }
    Mint operator-(const Mint& other) const { return Mint(value - other.value); }
    Mint operator*(const Mint& other) const { return Mint(1LL * value * other.value); }

    Mint pow(long long exp) const {
        Mint res = 1, base = value;
        while (exp > 0) {
            if (exp % 2) res = res * base;
            base = base * base;
            exp /= 2;
        }
        return res;
    }

    Mint inv() const { return pow(MOD - 2); }  // Fermat's little theorem
    Mint operator/(const Mint& other) const { return *this * other.inv(); }

    friend ostream& operator<<(ostream& os, const Mint& m) {
        return os << m.value;
    }
};

ull bin_exp(ull a, ull b){
    ull res = 1;
    while(b>0){
        if(b&1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}


// add other code snippet like sieve of erastosthenes

void solve(){
	int x, n, m; cin>>x>>n>>m;
    int k = x;
    int nn=n; int mm=m;
    while(k>0 && (n!=0 || m!=0)){
        if(k==1 && n>0){
            k = 0; break;
        } else if (k==1 && n==0) break;
        if(k&1 && n!=0) k /= 2, n--;
        else if(m>0) k = (k+1)/2, m--;
        else if(n>0) k /= 2, n--;

    }

    int min_k = k;
    int max_k = x;
    while(max_k>0 && (nn>0 || mm>0)){
        if(max_k==1 && nn>0){
            max_k = 0; break;
        } else if (max_k==1 && nn==0) break;
        if(max_k%2==0 && nn>0) max_k /= 2, nn--;
        else if(mm>0) max_k = (max_k+1)/2, mm--;
        else if(nn>0) max_k /= 2, nn--;

    }


    // int max_k = k;

    cout << min_k << ' ' << max_k << endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t; cin>>t; while(t-->0) solve(); return 0;
}