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
private:
    vector<int> postOrder;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        solve(root);
        return this->postOrder;
    }
    void solve(TreeNode* root) {
        if (!root)
            return;
        solve(root->left);
        solve(root->right);
        this->postOrder.emplace_back(root->val);
    }
};