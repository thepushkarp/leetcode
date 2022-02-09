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
    int maxi = INT_MIN;
    int maxSum(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int left = maxSum(node->left);
        int right = maxSum(node->right);
        int sum = node->val + max(0, left) + max(0, right);
        maxi = max(sum, maxi);
        sum = node->val + max(0, max(left, right));
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return maxi;
    }
};
