/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int dfs(TreeNode* p, int curr){
        if(!p) return 0;
        curr = (curr*2) + p->val;
        if(!p->left && !p->right) return curr;
        return dfs(p->left, curr) + dfs(p->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        if(!root->left && !root->right){
            return root->val;
        }
        return dfs(root, 0);
    }
};