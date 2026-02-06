
// Tree Diameter using Double DFS

vector<vector<int>> adj;
int n;

pair<int,int> dfs(int node, int parent, int dist) {
    pair<int,int> best = {dist, node};

    for(int nxt : adj[node]) {
        if(nxt == parent) continue;
        best = max(best, dfs(nxt, node, dist + 1));
    }
    return best;
}

int treeDiameter() {
    // Step 1: farthest from any node (say 0)
    auto p1 = dfs(0, -1, 0);
    int A = p1.second;

    // Step 2: farthest from A
    auto p2 = dfs(A, -1, 0);
    int diameter = p2.first;

    return diameter;
}

vector<vector<int>> adj;
int n;



//---------------------------------------
// DP on rooted trees (rerooting technique)

//---------------------------------------
// Rerooting DP - concise template
// Usage: customize `T`, `merge(a,b)`, and `add_root(a, v)` to your problem.
// - merge: combines two child results
// - add_root: incorporate the parent/root effect (if needed)
// Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Example type: change to suit your DP (struct or simple type)
using T = long long;
const T ID = 0; // identity for merge (example: 0 for sum)

// Customize these functions for your problem
T merge_val(const T &a, const T &b){
    // example: sum
    return a + b;
}
T add_root(const T &child_contrib, int v){
    // example: if node contributes +1 to its subtree size
    return child_contrib + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v; // 0-based preferred; if 1-based, subtract 1
        // if input is 1-based: u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> parent(n, -1), order; order.reserve(n);
    order.push_back(0);
    parent[0] = -2; // mark root's parent specially
    for(int i=0;i<(int)order.size(); ++i){
        int v = order[i];
        for(int to: g[v]) if(parent[to] == -1){
            parent[to] = v;
            order.push_back(to);
        }
    }

    // dp_down[v] = result for subtree of v considering v as root of subtree
    vector<T> dp_down(n, ID);

    // 1) bottom-up: compute dp_down
    for(int i=n-1;i>=0;--i){
        int v = order[i];
        T acc = ID;
        for(int to: g[v]) if(parent[to] == v){
            acc = merge_val(acc, add_root(dp_down[to], v));
        }
        dp_down[v] = acc;
    }

    // 2) top-down: compute answers for all roots using prefix/suffix trick
    vector<T> ans(n);
    // dp_up[v] = contribution from the parent side (excluding v's subtree)
    vector<T> dp_up(n, ID);

    for(int i=0;i<n;i++){
        int v = order[i];
        int sz = g[v].size();
        // collect children in a list (only those where parent[child]==v)
        vector<int> children;
        children.reserve(sz);
        for(int to: g[v]) if(parent[to] == v) children.push_back(to);

        int m = children.size();
        // prefix and suffix of merged child contributions
        vector<T> pref(m+1, ID), suf(m+1, ID);
        for(int j=0;j<m;j++){
            pref[j+1] = merge_val(pref[j], add_root(dp_down[children[j]], v));
        }
        for(int j=m-1;j>=0;j--){
            suf[j] = merge_val(add_root(dp_down[children[j]], v), suf[j+1]);
        }

        // The total when rooted at v is merging dp_up[v] (from parent side) with all children's contributions
        ans[v] = merge_val(dp_up[v], pref[m]);

        // propagate dp_up to children
        for(int j=0;j<m;j++){
            int c = children[j];
            // contribution excluding child c:
            T without_c = merge_val(dp_up[v], merge_val(pref[j], suf[j+1]));
            dp_up[c] = add_root(without_c, c); // when moving root to child, treat v side as one child
        }
    }

    // Output or use `ans` as needed. Example: print ans[i] for each node
    for(int i=0;i<n;i++){
        cout << ans[i] << (i+1==n? '\n' : ' ');
    }

    return 0;
}





