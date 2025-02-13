#include <bits/stdc++.h>
using namespace std;

struct TransNode{
    int key;
    
    vector<shared_ptr<TransNode>> children;
    shared_ptr<TransNode> parent;

    TransNode(int k, shared_ptr<TransNode> p) : key(k), parent(p) {}
};


bool found = false; shared_ptr<TransNode> leaf;
void dfs(const shared_ptr<TransNode>& n, int b){
    if(found) return;
    if(n->key == b){
        leaf = n;
        found = true;
        return;
    }
    for(const auto& child : n->children){
        dfs(child, b);
    }
}


void buildTree(int b, shared_ptr<TransNode>& n){
    if(n->key >= b) return;
    n->children.push_back(make_shared<TransNode>(2*n->key, n));
    n->children.push_back(make_shared<TransNode>(10*n->key+1, n));
    buildTree(b, n->children.front());
    buildTree(b, n->children.back());
}


void solve(){
    int a,b; cin>>a>>b;
    shared_ptr<TransNode> root = make_shared<TransNode>(a, nullptr);

    buildTree(b, root);
    dfs(root, b);

    vector<int> ans; 
    while(leaf != root){
        ans.push_back(leaf->key);
        leaf = leaf->parent;
    }
    ans.push_back(root->key);

    reverse(ans.begin(), ans.end());
    for(int num : ans) cout << num << " ";

    cout << '\n';
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	solve(); return 0;
}