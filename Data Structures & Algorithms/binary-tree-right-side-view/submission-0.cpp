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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        queue<TreeNode*> q;
        vector<int> result;
        q.push(root);

        while (!q.empty()) {
            TreeNode* last;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                last = q.front();
                q.pop();
                if (last->left != nullptr) q.push(last->left);
                if (last->right != nullptr) q.push(last->right);
            }
            result.push_back(last->val);
        }

        return result;
    }
};
