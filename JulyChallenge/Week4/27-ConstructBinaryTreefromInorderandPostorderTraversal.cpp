class Solution {
public:
    TreeNode* build(vector<int>& in, int x, int y, vector<int>& po, int a, int b) {
        if (x > y or a > b) {
            return nullptr;
        }
        TreeNode *node = new TreeNode(po[b]);
        int inStart = x;  
        while(node -> val != in[inStart]) {
            inStart++;
        }
        node->left = build(in, x, inStart - 1, po, a, a + inStart - x - 1);
        node->right = build(in, inStart + 1, y, po, a + inStart - x, b - 1);
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        return build(in, 0, in.size() - 1, po, 0, po.size() - 1);
    }
};
