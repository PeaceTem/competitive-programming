#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
// #define mp make_pair
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
#define int long long


void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<vector<int>> k(4, vector<int>(n));
    k[0][0] = k[1][0] = a[0];
    for(int i = 1; i < n; i++){
        k[0][i] = min(a[i], k[0][i - 1]);
        k[1][i] = max(a[i], k[1][i - 1]);
    }
    k[2].back() = k[3].back() = b.back();
    for(int i = n - 2; i >= 0; --i){
        k[2][i] = min(b[i], k[2][i + 1]);
        k[3][i] = max(b[i], k[3][i + 1]);
    }

    int ans = 0;
    vector<pair<int, int>> vp;
    for(int i = 0; i < n; i++){
        int ab = min(k[0][i], k[2][i]);
        int bc = max(k[1][i], k[3][i]);
        // do prev and next of each.

        // ans += ab * (2 * n - bc + 1);
        vp.push_back({bc, ab});
    }

    sort(vp.begin(), vp.end());
    // int l = 1;
    int i = 0;
    for(int l = 1; l <= 2 * n; l++){
        while(i < n && vp[i].second < l) i++;

        if(i >= n) break;
        ans += 2 * n - vp[i].first + 1;
    }
    
    cout << ans << endl;
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

