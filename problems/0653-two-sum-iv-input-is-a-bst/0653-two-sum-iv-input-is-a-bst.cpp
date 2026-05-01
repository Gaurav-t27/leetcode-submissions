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
    
    bool findTarget(TreeNode* root, int k) {
        
        stack<TreeNode*> ls;
        stack<TreeNode*> rs;

        TreeNode* currL = root;
        TreeNode* currR = root;
        while(currL) {
            ls.push(currL);
            currL = currL->left;
        }
        while(currR) {
            rs.push(currR);
            currR = currR->right;
        }

        while(!ls.empty() && !rs.empty()) {
            TreeNode* ln = ls.top();
            TreeNode* rn = rs.top();

            if(ln==rn) break;
            int sum = ln->val + rn->val;
            if(sum==k) return true;
            if(sum<k) {
                ls.pop();
                TreeNode* node = ln->right;
                while(node) {
                    ls.push(node);
                    node = node->left;
                }
            } else {
                rs.pop();
                TreeNode* node = rn->left;
                while(node) {
                    rs.push(node);
                    node = node->right;
                }
            }
        }
        return false;
    }
};