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
    int depthUtil(TreeNode* node, int x, int level) {
        if (node == nullptr) {
            return -1;
        }
        if (x == node->val) {
            return level;
        }
        int downlevel = depthUtil(node->left, x, level + 1);
        if (downlevel != -1)
            return downlevel;
        downlevel = depthUtil(node->right, x, level + 1);
        return downlevel;
    }
    int depth(TreeNode* node, int x) {
        return depthUtil(node, x, 0);
    }
    int parent(TreeNode* node, int x) {
        if (node == nullptr) {
            return -1;
        }
        if ((node->left != nullptr and x == node->left->val) or (node->right != nullptr and x == node->right->val)) {
            return node->val;
        }
        int par = parent(node->left, x);
        if (par != -1)
            return par;
        par = parent(node->right, x);
        return par;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(depth(root, x) == depth(root, y)) {
            if (parent(root, x) != parent(root, y)) {
                return true;
            }
            return false;
        }
        return false;
    }
};
