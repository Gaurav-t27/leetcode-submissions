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
    int maxFreq = 0, currFreq = 0;
    TreeNode * prev = nullptr;
    vector<int> modes;
public:
    void handleVal(int val) {
        if(prev && val == prev->val) 
            currFreq++;
        else
            currFreq = 1;

        if(currFreq > maxFreq) {
            maxFreq = currFreq;
            modes = {val};
        } else if(currFreq == maxFreq) {
            modes.push_back(val);
        }
    }
    void inOrder(TreeNode* root) {
        if(!root) return;

        inOrder(root->left);
        handleVal(root->val);
        prev = root;
        inOrder(root->right);

    }
    vector<int> findMode(TreeNode* root) {
        maxFreq = 0;
        currFreq = 0;
        prev = nullptr;
        modes.clear();
        
        inOrder(root);
        return modes;
    }
};