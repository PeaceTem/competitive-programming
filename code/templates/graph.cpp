// Bipartite Graph Check Template

#include <bits/stdc++.h>
using namespace std;

bool is_bipartite(int n, const vector<vector<int>>& g) {
    vector<int> color(n, -1);

    for(int start = 0; start < n; start++) {
        if(color[start] != -1) continue;

        queue<int> q;
        color[start] = 0;
        q.push(start);

        while(!q.empty()) {
            int v = q.front(); q.pop();
            for(int u : g[v]) {
                if(color[u] == -1) {
                    color[u] = color[v] ^ 1;
                    q.push(u);
                } 
                else if(color[u] == color[v]) {
                    return false; // conflict with same color
                }
            }
        }
    }
    return true;
}
