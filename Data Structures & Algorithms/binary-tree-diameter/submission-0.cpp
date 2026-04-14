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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        return helper(root).second;
    }
private:
    // first is the height of the current node, second is the max answer so far.
    pair<int, int> helper(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        if (root->left == nullptr && root->right == nullptr) return {1, 0};

        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);

        return {max(left.first, right.first) + 1, max({left.second, right.second, left.first + right.first})};
    }
};

// the formula is: 
// height_left - 1 + height_right - 1 + 2 = left + right 
// basically a leaf has a height of 1, and stuff works out
