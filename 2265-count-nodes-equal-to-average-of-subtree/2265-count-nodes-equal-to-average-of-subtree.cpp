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
    int ans;
    pair<int, int> dfs(TreeNode* n){
        if((n->left==nullptr) && (n->right==nullptr)) {
            ans++;
            return {n->val, 1};
        }
        pair<int, int> r = {0, 0}, l = {0, 0};
        if(n->left) l = dfs(n->left);
        if(n->right) r = dfs(n->right);
        int sum = n->val+l.first+r.first;
        int cnt = l.second+r.second+1; 
        if(sum/cnt == n->val) ans++;
        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        ans = 0;
        dfs(root);
        return ans;
    }
};