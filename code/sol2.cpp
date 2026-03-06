#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

#define int long long

vector<vector<int>> adj;
vector<int> ans;
vector<int> sz;
int n, k;

void dfs(int u, int parent){
    sz[u] = 1;

    for(int v : adj[u]){
        if(v == parent) continue;

        dfs(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int parent){
    for(int v : adj[u]){
        if(v == parent) continue;

        int sv = sz[v];
        int su = sz[u];

        int cur = ans[u];

        if(sv >= k) cur--;

        sz[u] -= sz[v];
        sz[v] = n;

        if(sz[u] >= k) cur++;

        ans[v] = cur;

        dfs2(v, u);

        sz[u] = su;
        sz[v] = sv;
    }
}

void solve(){
    cin >> n >> k;

    int nn = n;

    adj.assign(n + 1, vector<int>());
    ans.assign(n + 1, 0);
    sz.assign(n + 1, 0);

    while(--nn){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int b = 0;

    for(int i = 0; i <= n; i++){
        if(sz[i] >= k) b++;
    }

    ans[1] = b;

    dfs2(1, 0);

    int final_ans = 0;
    for(int i = 1; i <= n; i++) final_ans += ans[i];

    cout << final_ans << endl;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    while(t-->0){
        solve();
    }
    return 0;
}

