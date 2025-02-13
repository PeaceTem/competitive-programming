#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <cmath>
using namespace std;

struct Node {
    vector<int> key;
    map<int, Node*> children;
};

int validLength(const vector<int>& branch) {
    unordered_set<int> seen;
    int len = 0;
    for (int x : branch) {
        if (seen.count(x))
            break;
        seen.insert(x);
        len++;
    }
    return len;
}

void dfs(Node* node, int &maxValid) {
    int cur = validLength(node->key);
    if(cur > maxValid)
        maxValid = cur;
    
    for(auto &childPair : node->children)
        dfs(childPair.second, maxValid);
}

void buildGraph(Node* node, const vector<vector<int>>& matrix, int col) {
    int n = matrix[0].size();
    if(col >= n) return;

    bool foundOne = false;
    int numRows = matrix.size();
    for (int row = 0; row < numRows; row++) {
        if(matrix[row][col] == 1) {
            foundOne = true;
            int candidate = row + 1; // use 1-indexed value for the queue

            // Do not append if the last appended is the same (avoid consecutive duplicates)
            if (!node->key.empty() && node->key.back() == candidate) {
                // Even if we do not change the branch, we continue processing next column.
                buildGraph(node, matrix, col + 1);
            } else {
                // Create a child for this candidate if it does not exist.
                if (node->children.find(candidate) == node->children.end()) {
                    Node* child = new Node();
                    child->key = node->key;
                    child->key.push_back(candidate);
                    node->children[candidate] = child;
                }
                // Continue building from that child.
                buildGraph(node->children[candidate], matrix, col + 1);
            }
        }
    }
    // If no 1 was found in this column, simply continue with the same branch.
    if(!foundOne)
        buildGraph(node, matrix, col + 1);
}

// --- (Optional) Recursive function to free all nodes in the tree ---
void freeTree(Node* node) {
    for(auto &childPair : node->children) {
        freeTree(childPair.second);
    }
    delete node;
}

// --- Main ---
// For each test case, the program reads n and an n x n matrix.
// It then builds the tree and finds the maximum valid branch length,
// and finally outputs (maxValidLength + 1).
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // Read the n x n matrix.
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> matrix[i][j];
            }
        }

        // Create the root node (empty branch).
        Node* root = new Node();

        // Build the tree from column 0.
        buildGraph(root, matrix, 0);

        // Traverse the tree to find the maximum valid branch length.
        int maxValid = 0;
        dfs(root, maxValid);

        // The answer is (maxValid length + 1) as specified.
        cout << min(n, maxValid + 1) << "\n";

        // Free the allocated memory.
        freeTree(root);
    }
    return 0;
}
