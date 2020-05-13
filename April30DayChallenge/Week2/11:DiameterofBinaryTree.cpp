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
    int height(TreeNode* node) {
        if (node == nullptr) {
            return -1;
        }
        return max(height(node->left), height(node->right)) + 1;
    }
    int diam(TreeNode* node, int maxi) {
        if (node == nullptr) {
            return 0;
        }
        maxi = max(maxi, height(node->left) + height(node->right) + 2);
        maxi = max(maxi, diam(node->left, maxi));
        maxi = max(maxi, diam(node->right, maxi));
        return maxi;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diam(root, 0);
    }
};
