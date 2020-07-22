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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};  
        vector<vector<int>> ans;
        queue<TreeNode*> q;  
        q.push(root);
        int par = 0;
        while (!q.empty()) {
            int nodeCount = q.size();
            vector<int> v;
            while (nodeCount) {  
                TreeNode* node = q.front();  
                v.push_back(node-> val);  
                q.pop();  
                if (node -> left != nullptr) {
                    q.push(node -> left);  
                } 
                if (node -> right != nullptr) {
                    q.push(node -> right);  
                }
                nodeCount--;  
            }
            if (par++ % 2) {
                reverse(v.begin(), v.end());
            }
            ans.push_back(v); 
        }
        return ans;
    }
};
