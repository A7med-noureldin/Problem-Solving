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
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
       queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()){
            TreeNode *tmp = q.front();
            q.pop();
            v.push_back(tmp->val);
            if(!tmp->left && !tmp->right)continue;
            if(tmp->left != NULL){
                q.push(tmp->left);
            }
            if(tmp->right != NULL){
                q.push(tmp->right);
            }
        }
        sort(v.begin(), v.end());
        int mini = 1e5+20;
        for(int i = v.size()-1; i > 0; i--){
            mini = min(mini, v[i]-v[i-1]);
        }
        return mini;
    }
};