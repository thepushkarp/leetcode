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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1 });
        while (!q.empty()) {
            int nodeCount = q.size();
            ans = max(ans, (q.back().second - q.front().second) + 1);
            while (nodeCount--) {
                pair<TreeNode*, int> temp = q.front();
                q.pop();
                if (temp.first -> left != nullptr) {
                    q.push({temp.first -> left, 2 * (long)temp.second});
                }
                if (temp.first -> right != nullptr) {
                    q.push({temp.first -> right, 2 * (long)temp.second + 1});
                }
            }
        }
        return ans;
    }
};

