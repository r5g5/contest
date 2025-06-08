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
    vector<int> largestValues(TreeNode* root) {
        constexpr int N = (int) 1e4 + 1;
        queue<TreeNode> q;
        q.push(root);
        vector<int> d(N, 0);
        d[0] = 0;
        int count = 1;
        while (!q.empty())
        {
            auto node = q.top(); q.pop();
            if (node->left) {
                // TODO: Rahul
            }
        }
    }
};