//---------------------------
// Count Unique Paths in a Complete Graph
// Given a complete graph with n nodes, count the number of unique paths of length 2
//---------------------------

Total paths = n * (n - 1) / 2



//---------------------------
// Count Paths of Length K in a Tree
// Given a tree with n nodes, count the number of unique paths of length K.
//---------------------------

int n, K;
vector<vector<int>> adj;
vector<int> dist;
long long answer = 0;

void dfs(int u, int p, int depth) {
    dist[u] = depth;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, depth + 1);
    }
}

long long count_paths_length_K() {
    answer = 0;

    for(int start = 0; start < n; start++) {
        dist.assign(n, -1);

        // run DFS from each node
        dfs(start, -1, 0);

        // count nodes exactly K away
        for(int i = 0; i < n; i++) {
            if(dist[i] == K) answer++;
        }
    }

    // each path counted twice (u->v and v->u)
    return answer / 2;
}
