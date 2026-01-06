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
    // map<int, long long> mp;
    // void dfs(TreeNode *x, int lvl){
    //     if(!x) return;
    //     mp[lvl] += x->val;
    //     dfs(x->left, lvl+1);
    //     dfs(x->right, lvl+1);
    // }
    int maxLevelSum(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        // dfs(root, 1);
        // int ans = 0, maxi = INT_MIN;
        // for(auto [p, q] : mp){
        //     if(q > maxi){
        //         maxi = q;
        //         ans = p;
        //     }
        // }
        // return ans;

        queue<TreeNode*> q;
        q.push(root);
        int currLvl = 1, maxi = INT_MIN, ans = 0;
        while(!q.empty()){
            int siz = q.size();
            int sum = 0;

            while(siz--){
                TreeNode *p  = q.front();
                q.pop();
                sum += p->val;
                if(p->left != NULL) q.push(p->left);
                if(p->right != NULL) q.push(p->right);
            }
            if(sum > maxi){
                maxi = sum, ans = currLvl;
            }
            currLvl++;
        }
        return ans;
    }
};