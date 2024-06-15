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
    void getPath(TreeNode *root, vector<int> &path, int x,vector<vector<int>> &ans){
        if(!root) return;

        path.push_back(root->val);

        if(root->val==x && !root->left && !root->right){
            ans.push_back(path);
        }

        getPath(root->left,path,x-root->val,ans);
        getPath(root->right,path,x-root->val,ans);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        if(root==NULL){
            return ans;
        }
        getPath(root,path,targetSum,ans);
        return ans;
    }
};