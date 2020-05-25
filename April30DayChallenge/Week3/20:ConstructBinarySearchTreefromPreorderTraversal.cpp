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
    int index = 0;
    TreeNode* constructTree(vector<int>& preorder, int mini, int maxi, int size) {
        if( index >= size )
            return nullptr;
        TreeNode* curr = nullptr;
        int currData = preorder[index];
        if ((currData > mini) and (currData < maxi))
        {
            curr = new TreeNode(currData);
            index++;
            curr -> left  = constructTree(preorder, mini, currData, size );
            curr -> right = constructTree(preorder, currData, maxi, size );
        }
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int size = preorder.size();
        return constructTree(preorder, INT_MIN, INT_MAX, size);
    }
};
