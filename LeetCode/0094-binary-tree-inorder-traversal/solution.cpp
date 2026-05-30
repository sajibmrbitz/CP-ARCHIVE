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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> values={};
        if(root==nullptr){
            return values;;
        }

        values=inorderTraversal(root->left);
        values.push_back(root->val);
        vector<int> rightvalues=inorderTraversal(root->right);
        values.insert(values.end(),rightvalues.begin(),rightvalues.end());

        return values;
    }
};
