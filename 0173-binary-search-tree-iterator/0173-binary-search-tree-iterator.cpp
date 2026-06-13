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

class BSTIterator {
    TreeNode* root;
    int idx;
    vector<int> tree;
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        idx = 0;
        inorderDfs(root);
    }

    void inorderDfs(TreeNode* p){
        if(!p) return;
        inorderDfs(p->left);
        tree.push_back(p->val);
        inorderDfs(p->right);
    }

    int next() {
        return tree[idx++];
    }
    
    bool hasNext() {
        if(idx < tree.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */