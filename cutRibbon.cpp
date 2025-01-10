#include <bits/stdc++.h>

using namespace std;
short n, a, b, c, newValue; vector<short> v; map<short, short> dp;


struct TreeNode {
    short value;  
    short level;
    vector<shared_ptr<TreeNode>> children; 

    TreeNode(short val, short lvl) : value(val), level(lvl) {}
};



void buildTree(const shared_ptr<TreeNode>& node) {

    for (short sub : v) {
        newValue = node->value - sub;
        if (newValue >= 0) {
            auto child = make_shared<TreeNode>(newValue, node->level + 1);
            node->children.push_back(child);

            
            if(dp.count(child->value)){
                if(dp.at(child->value) < child->level){
                    dp[child->value] = child->level;
                    buildTree(child);
                }
            } else {
                dp.insert({child->value, child->level});
                buildTree(child);
            }
        }
    }
}


int main(){
    cin >> n >> a >> b >> c;
    v = {a, b, c};
    sort(v.begin(), v.end());
    auto root = make_shared<TreeNode>(n, 0);
    buildTree(root);
    cout << dp.at(0) << endl;
    return 0;
}