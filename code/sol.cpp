#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define F first
#define S second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ld long double
#define eps 1e-9
#define int long long

const int MOD = 998244353;
const int N = 52;
int fact[N];

void compute(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

int mod_exp(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i <= n; i++) cin >> a[i];

    int acc = accumulate(all(a), 0LL);
    int k = acc / n;
    int z = 0;
    for(int i = 1; i <= n; i++){
        a[i] -= k;

        if(a[i] < 0){
            a[0] += a[i];
            a[i] = 0;
        }

        if(a[i] > 1 || a[0] < 0){
            cout << 0 << endl; return;
        }

        if(a[i] == 0) z++;
    }

    if(a[0] < 0){
        cout << 0 << endl; return;
    }

    int x = z - a[0];

    if(x < 0){
        cout << 0 << endl; return;
    }

    int p = min(x, z - x);
    int ans = 1;
    for(int i = 1; i <= p; i++){
        ans = ((ans * (z - i + 1)) % MOD) * mod_exp(i, MOD - 2) % MOD;
    }
    ans = ((ans * fact[x]) % MOD) * fact[n - x] % MOD;

    cout << ans << endl;
    // I'm tired, but it doesn't matter.
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t = 1; 
    compute();
    cin >> t;
    while(t-->0){
        solve();
    }
    return 0;
}

