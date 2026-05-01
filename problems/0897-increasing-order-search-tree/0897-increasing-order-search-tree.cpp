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
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode * curr = root;
        stack<TreeNode*> s;
        TreeNode * dummy = new TreeNode(0);
        TreeNode * prev = dummy;

        while(curr || !s.empty()) {
            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            curr->left = nullptr;
            prev->right = curr;
            prev = curr;

            curr = curr->right;
        }
        TreeNode * result = dummy->right;
        delete dummy;
        return result;
    }
};