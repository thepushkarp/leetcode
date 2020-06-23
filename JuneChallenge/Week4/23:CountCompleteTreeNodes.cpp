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
    int countNodes(TreeNode* root) {
        int hr= 0, hl = 0;
        TreeNode* l = root;
        TreeNode* r = root;
        while(l) {
            hl++;
            l = l -> left;
        }
        while(r) {
            hr++;
            r = r -> right;
        }
        if (hl == hr) return (1 << hl) - 1;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};

