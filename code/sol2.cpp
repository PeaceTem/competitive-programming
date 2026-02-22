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
    int n, h, k; cin >> n >> h >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int acc = accumulate(all(a), 0LL);
    int ans = 0;
    ans += (h / acc) * n + (h / acc)  * k;
    // int pp = (h / 
    h %= acc;
    if(h == 0LL){
        cout << ans - k << endl; return;
    }

    int hh = h;
    int mn = LLONG_MAX;
    // int mn_idx = 1;
    int mx = LLONG_MIN;
    for(int i = 0; i < n; i++){
        if(hh <= a[i]){
            // find the max element from a[i] -> a[n - 1]
            mx = *max_element(a.begin() + i, a.end());
            break;
        } else hh -= a[i];
    }

    if(mx >= h){
        cout << ans + 1 << endl;
        return;
    }

    vector<int> pref(n + 1);
    pref[0] = 0;

    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i - 1];
    }

    int need = h - mx;
    int xx = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        int k = need - pref[i - 1];
        if(k <= 0){
            xx = min(xx, i);
            break;
        }
        // lower_bound
        int ind = lower_bound(all(pref), pref[i] + k) - pref.begin();

        xx = min(xx, ind);
    }

    cout << ans + xx << endl;

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

