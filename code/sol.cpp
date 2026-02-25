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
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    stack<pair<int, int>> st, st1;
    for(int i = 0; i < n; i++) st.push({a[i], i});

    while(!st.empty()){
        if(st1.empty() || st1.top().F != st.top().F + 1) st1.push(st.top()), st.pop();
        else st1.pop();
    }
    // cout << st1.size() << endl;

    vector<int> base(n, 0), pref(n, 0);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!st1.empty() && st1.top().S == i){
            base[i] = 1, st1.pop();
        } else{
            base[i] = 0;
        }
    }
    pref[0] = base[0];
    for(int i = 1; i < n; i++){
        pref[i] = pref[i - 1] + base[i];
    }

    // pref1[0] = pref[0];
    // for(int i = 1; i < n; i++){
    //     pref1[i] = pref1[i - 1] + pref[i];
    // }
    
    int acc = accumulate(all(pref), 0LL);
    ans = acc;
    for(int i = 1; i < n; i++){
        if(base[i] == 0){
            acc--;
        } else acc -= n - i + 1;

        ans += acc;
    }
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[a[i]] = i;
        if(base[i] != 0) continue;
        ans += (i - mp[a[i] - 1] - 1) * (n - i);
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

