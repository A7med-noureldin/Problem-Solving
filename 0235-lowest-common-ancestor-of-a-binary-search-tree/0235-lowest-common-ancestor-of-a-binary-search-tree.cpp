/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)return;
        if((root->val >= p->val && root->val <= q->val) || 
          (root->val <= p->val && root->val >= q->val)){
            ans = root;
            return;
        }
        dfs(root->left, p, q);
        dfs(root->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val) 
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};