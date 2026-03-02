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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    vector<int> p(n + m + 1, 0);

    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[a[i]]++;
    }

    for(auto& [k, v] : mp){
        for(int i = k; i <= n + m; i += k){
            p[i] += v;
        }
    }

    int alice = 0, bob = 0, both = 0;

    for(int i = 0; i < m; i++){
        if(p[b[i]] == n) alice++;
        else if(p[b[i]] == 0){
            // cout << "Bob's own: " << b[i] << endl;
            bob++;
        }
        else both++;
    }
    // cout << alice << " " << bob << " " << both << endl;

    alice += (both + 1) / 2;
    bob += both / 2;
    // cout << alice << " " << bob << " " << both << endl;
    if(alice > bob) cout << "Alice\n";
    else cout << "Bob\n";
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

