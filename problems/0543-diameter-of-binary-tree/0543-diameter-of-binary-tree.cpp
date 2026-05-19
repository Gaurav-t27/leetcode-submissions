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
    int height(TreeNode* node, int& max_diameter) {
        if(!node) return 0;

        int lh = height(node->left, max_diameter);
        int rh = height(node->right, max_diameter);
        max_diameter = max(max_diameter, lh+rh);

        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int max_diameter = 0;
        height(root, max_diameter);
        return max_diameter;
    }
};