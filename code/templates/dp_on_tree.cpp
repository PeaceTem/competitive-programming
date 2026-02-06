vector<int> adj[N];
int dp[N];

void dfs(int u, int parent) {
    // 1. initialize dp[u]
    dp[u] = base_value;

    for (int v : adj[u]) {
        if (v == parent) continue;

        dfs(v, u);          // postorder: process child first
        dp[u] += dp[v];     // combine child's result
    }
}


void dfs(int u, int p){
    dp[u] = base_value;

    for(int)
}

vector<int> parent, size;

int find(int a){
    return (parent[x] == a) ? a : parent[x] = find(parent[x]);
}