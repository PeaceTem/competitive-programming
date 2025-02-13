#include <bits/stdc++.h>

using namespace std;
struct ParkNode{
    short c;
    short v;

    vector<shared_ptr<ParkNode>> children;

    ParkNode(short val, short cat) : v(val), c(cat) {}
};


unordered_map<short, vector<ParkNode>> graph;
vector<short> sol; short mc;

void dfs(const shared_ptr<ParkNode>& node, short nc){
    short new_c = node->c ? nc + node->c : 0;
    vector<short> valid_children;
    for(const auto& n : node->children){
        if(n->v > node->v) valid_children.push_back(n->v);
    }

    if(valid_children.size() == 0 && new_c <= mc){
        if(find(sol.begin(), sol.end(), node->v) == sol.end()) sol.push_back(node->v);
    } else if (new_c <= mc) for(const auto& child : node->children) dfs(child, new_c);
}


int main(){
    short n, x; cin >> n >> mc; unordered_map<short, shared_ptr<ParkNode>> nodes;

    for(short i=1; i <= n; i++){
        cin >> x;
        auto node = make_shared<ParkNode>(i, x);
        nodes[i] = node;
    }

    short first, second;

    for(short i=1; i < n; i++){
        cin >> first >> second;
        nodes.at(first)->children.push_back(nodes.at(second));
        nodes.at(second)->children.push_back(nodes.at(first));
    }

    for(const auto& ch : nodes.at(1)->children) cout << ch->v << " ";
    cout << endl;
    dfs(nodes.at(1), 0);

    cout << sol.size() << endl;
    for(short in : sol) cout << in << " ";
    cout << endl;

    return 0;
}