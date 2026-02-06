// Reverse Odd Levels of Binary Tree
TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;

        dfs(root->left, root->right, 1);

        return root;   
    }

    void dfs(TreeNode* left, TreeNode* right, int level){
        if(!left || !right) return;

        if(level & 1) {
            swap(left->val, right->val);
        }

        dfs(left->left, right->right, level + 1);
        dfs(left->right, right->left, level + 1);
    }