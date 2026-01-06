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
    map<int, long long> mp;
    void dfs(TreeNode *x, int lvl){
        if(!x) return;
        mp[lvl] += x->val;
        dfs(x->left, lvl+1);
        dfs(x->right, lvl+1);
    }
    int maxLevelSum(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        dfs(root, 1);
        int ans = 0, maxi = INT_MIN;
        for(auto [p, q] : mp){
            if(q > maxi){
                maxi = q;
                ans = p;
            }
        }
        return ans;
    }
};