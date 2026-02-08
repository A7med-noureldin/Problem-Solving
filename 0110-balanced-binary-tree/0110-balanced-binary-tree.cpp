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
    bool notBalanced;
    int hight(TreeNode* root){
        if(!root) return 0;
        int l = hight(root->left);
        int r = hight(root->right);
        if(abs(l-r) > 1) notBalanced = true;
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        notBalanced = false;
        hight(root);
        return !notBalanced;
    }
};