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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        unordered_map<TreeNode*, int> height;

        stack<TreeNode*> s1;
        s1.push(root);
        stack<TreeNode*> s2;
        while(!s1.empty()) {
            TreeNode* curr = s1.top();
            s1.pop();
            s2.push(curr);

            if(curr->left) s1.push(curr->left);
            if(curr->right) s1.push(curr->right);
        }

        while(!s2.empty()) {
            TreeNode * curr = s2.top();
            s2.pop();
            int lh = curr->left ? height[curr->left]:0;
            int rh = curr->right ? height[curr->right]:0;

            if(abs(lh-rh) > 1) return false;
            height[curr] = 1 + max(lh,rh);
        }
        return true;
    }
};