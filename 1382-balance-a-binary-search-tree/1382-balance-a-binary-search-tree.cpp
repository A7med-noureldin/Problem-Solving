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
    vector<int> nodes;

    void dfs(TreeNode* p){
        if(!p) return;
        dfs(p->left);
        nodes.push_back(p->val);
        dfs(p->right);
    }

    TreeNode* balance(int s, int e){
        if(s > e) return NULL;
        int mid = s + (e-s)/2;
        TreeNode* l = balance(s, mid-1);
        TreeNode* r = balance(mid+1, e);
        return new TreeNode(nodes[mid], l, r);
    }

    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return balance(0, nodes.size()-1);
    }
};