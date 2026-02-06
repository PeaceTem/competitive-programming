
// Euler Tour of a Tree
vector<int> adj[200005];
int tin[200005], tout[200005], euler[200005], timer = 0;

void dfs(int u, int p){
    tin[u] = timer;
    euler[timer] = u;
    timer++;

    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v, u);
    }

    tout[u] = timer - 1;
}

// Subtree queries using Euler Tour
euler[tin[u] ... tout[u]]

void dfs(int u, int p) {
    tin[u] = timer;
    euler[timer] = u;
    timer++;

    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
    }

    tout[u] = timer - 1;
}

// Maximum path sum in a tree
int mx = INT_MIN;

    int post(TreeNode* root){
        if(!root) return 0;

        int ld = INT_MIN, rd = INT_MIN;
        ld = max(0, post(root->left));
        rd = max(0, post(root->right));
        mx = max(root->val + ld + rd, mx);
        return root->val + max(ld, rd);
    }

    int maxPathSum(TreeNode* root) {
        mx = INT_MIN;
        int k = post(root);
        return max(mx, k);
    }