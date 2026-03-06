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


vector<vector<int>> adj;
vector<int> cnt;
vector<int> mx;
vector<int> ans;
vector<int> ans_s;
vector<int> cnt_s;


void dfs(vector<int>& a, int p, int parent){
    int sm = 0, cnt_sm = 0;
    int mx1 = 0, mx2 = 0;
    
    for(int u : adj[p]){
        if(u == parent) continue;

        dfs(a, u, p);

        if(mx[u] >= mx1){
            mx2 = mx1;
            mx1 = mx[u];
        } else if(mx[u] >= mx2){
            mx2 = mx[u];
        }

        sm += cnt[u];
        // ans_sm += ans_s[u];
        cnt_sm += cnt_s[u];
        // cout << sm << " ";
    }


    cnt[p] = a[p] + 2 * sm; // aug_sm
    cnt_s[p] = a[p] + cnt_sm; // sum
    mx[p] = mx1 + 1;
    ans[p] = 0;
    for(int u : adj[p]){
        if(u == parent) continue;
        if(mx[u] == mx1){
            if(mx2 == 0){
                ans[p] = max(ans[p], ans[u] + cnt_s[u]);
            } else {
                ans[p] = max(ans[p], mx2 * cnt_s[u] + sm);
            }
        } else {
            // ans[p] = max(ans[p], (mx1 - 1) * cnt[u] + sm + cnt_s[u]);
            ans[p] = max(ans[p], mx1 * cnt_s[u] + sm);

        }
    }

    

}

void solve(){
    int n; cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    int nn = n;
    int u, v; 

    adj.assign(n + 1, vector<int>());
    cnt.assign(n + 1, 0);
    mx.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    ans_s.assign(n + 1, 0);
    cnt_s.assign(n + 1, 0);



    while(--nn){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(a, 1, 0);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    cout << endl;
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

