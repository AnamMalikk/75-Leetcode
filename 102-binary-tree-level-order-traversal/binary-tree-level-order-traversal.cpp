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
    void Level(TreeNode*root,int index,vector<vector<int>>& ans){
        if(root==nullptr){
            return ;
        }
        if(ans.size()<=index){
            ans.push_back({root->val});
        }else{
            ans[index].push_back(root->val);
        }
        Level(root->left,index+1,ans);
        Level(root->right,index+1,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int index=0;
        vector<vector<int>>ans;
        Level(root,index,ans);
        return ans;
    }
};