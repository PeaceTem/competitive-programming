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

void solve(){
    int n, l, r, k; cin >> n >> l >> r >> k;

    if(n % 2 == 0) {
        if(n == 2){
            cout << -1 << endl; return;
        }

        int pos = log2(l);
        // learn how to use __builtin_clzll(l);
        
        int kk = 1LL << (pos + 1);

        if(r < kk){
            cout << -1 << endl; return;
        }

        if(k <= n - 2) cout << l << endl;
        else cout << kk << endl;

        return;
    }

    cout << l << endl;
}


int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t = 1; 
    cin >> t;
    while(t-->0){
        solve();
    }
    return 0;
}

