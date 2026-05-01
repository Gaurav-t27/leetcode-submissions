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
    TreeNode* prev{nullptr};
public:
    void inOrder(TreeNode* root, int& diff) {
        if(!root) return;

        inOrder(root->left, diff);

        if(prev) {
            diff = min(diff, abs(prev->val - root->val));
        }
        prev = root;
        inOrder(root->right, diff);
    }
    int getMinimumDifference(TreeNode* root) {
        prev = nullptr;
        int min_diff = INT_MAX;
        inOrder(root, min_diff);
        return min_diff;
        /*stack<TreeNode*> s;
        TreeNode * curr = root;
        TreeNode * prev = nullptr;
        int min_diff = INT_MAX;
        while(curr || !s.empty()) {
            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if(prev) {
                min_diff = min(min_diff, abs(curr->val - prev->val));
                
            }
            prev = curr;
            curr = curr->right;
        }
        return min_diff;*/
    }
};