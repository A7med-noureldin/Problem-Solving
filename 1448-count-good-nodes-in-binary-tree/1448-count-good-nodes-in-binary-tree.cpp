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
    int ans = 0;
    void dfs(TreeNode* n, int maxi){
        if(!n) return;
        if(n->val >= maxi) ans++;
        dfs(n->left, max(maxi, n->val));
        dfs(n->right, max(maxi, n->val));
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans; 
    }
};