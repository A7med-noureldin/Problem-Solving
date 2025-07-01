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
    vector<string> ans;
    void backtrack(TreeNode* root, string path){
        if(!root){
            return;
        }
        if (!path.empty()) path += "->";
        path += to_string(root->val);
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }
        backtrack(root->left, path);
        backtrack(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root){
            return vector<string>();
        }
        backtrack(root, "");
        return ans;
    }
};