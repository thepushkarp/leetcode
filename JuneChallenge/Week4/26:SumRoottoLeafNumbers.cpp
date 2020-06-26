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
    int sumNumbersHelper(TreeNode* node, int sum) {
        if (node == nullptr)
            return 0;
        sum = sum*10 + node -> val;
        if (node -> left == nullptr and node -> right == nullptr)
            return sum;
        return sumNumbersHelper(node -> left, sum) + sumNumbersHelper(node -> right, sum);
    }
    int sumNumbers(TreeNode* root) {
        return sumNumbersHelper(root, 0);
    }
};

