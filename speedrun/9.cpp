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
	int w, d, h;
    cin>>w>>d>>h;
    int a,b,f,g;
    cin>>a>>b>>f>>g;

    // int mnx = min(a,f);
    // int mxx = max(a,f);
    // int k = mxx - mnx;
    // int ans_x = b + g + k + h;
    // int mny = min(b,g);
    // int mxy = max(b,g);
    // int k1 = mxy - mny;
    // int ans_y = a+f+k1+h;
    int x1 = (w-a)+(w-f) + abs(b-g) + h;
    int x2 = a+f + abs(b-g) + h;
    int y1 = (d-b)+(d-g) + abs(a-f) + h;
    int y2 = b+g + abs(a-f) + h;
    cout << min(x1, min(x2, min(y1, y2))) << endl;

    
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int t=1; cin>>t; while(t-->0) solve(); return 0;
}