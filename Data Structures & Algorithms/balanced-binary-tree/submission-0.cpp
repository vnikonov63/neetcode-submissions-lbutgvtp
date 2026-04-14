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
    // height of an nullptr is 0.
    // height of a leaf is 1.

    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }

private:
    pair<bool, int> helper(TreeNode* root) {
        if (!root) {
            return {true, 0};
        }
        pair<bool, int> left = helper(root->left);
        pair<bool, int> right = helper(root->right);

        bool balance_status = left.first && right.first && (abs(left.second - right.second) <= 1);
        int height = 1 + max(left.second, right.second);

        return {balance_status, height};
    }
};
