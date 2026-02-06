// Tree DP with post order traversal

class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> children_label;
    string labelss;

    void dfs(int u, int p){

        for(int nxt : adj[u]){
            if(nxt == p) continue;
            dfs(nxt, u);
            for(int i = 0; i < 26; i++){
                children_label[u][i] += children_label[nxt][i];
            }
        }
    }


    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.clear(); adj.resize(n);
        children_label.assign(n, vector<int>(26, 0));
        labelss = labels;

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            children_label[i][labels[i] - 'a']++;
        }


        dfs(0, -1);

        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            ans[i] = children_label[i][labels[i] - 'a'];
        }

        return ans;
    }
};