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

    TreeNode* solver(TreeNode* root)
    {
        if(!root) return NULL;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        solver(root->left);
        solver(root->right);
        return root;

    }

    TreeNode* invertTree(TreeNode* root) {
        return solver(root);
    }
};