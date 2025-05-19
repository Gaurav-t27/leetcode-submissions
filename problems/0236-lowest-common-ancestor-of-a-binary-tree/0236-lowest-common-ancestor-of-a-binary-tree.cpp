/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        unordered_map<TreeNode *, TreeNode *> parentMap;
        parentMap[root] = nullptr;

        stack<TreeNode*> st;
        st.push(root);

        while(parentMap.find(p) == parentMap.end() || parentMap.find(q) == parentMap.end())
        {
            TreeNode* curr = st.top();
            st.pop();

            if(curr->left)
            {
                parentMap[curr->left] = curr;
                st.push(curr->left);
            }

            if(curr->right)
            {
                parentMap[curr->right] = curr;
                st.push(curr->right);
            }
        }

        unordered_set<TreeNode*> ancestors;
        while(p)
        {
            ancestors.insert(p);
            p = parentMap[p];
        }

        while(ancestors.find(q) == ancestors.end())
        {
            q = parentMap[q];
        }

        return q;
    }
};