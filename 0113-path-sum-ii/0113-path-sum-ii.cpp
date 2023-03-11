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
   
    void solve(TreeNode *root, int targetSum,vector<int>ans, vector<vector<int>>&result){
        if(root==NULL)
            return;
        ans.push_back(root->val);
        targetSum = targetSum - root->val;
        if(root->left==NULL&&root->right==NULL&&targetSum==0){
            result.push_back(ans);
            return;
        }
        
        solve(root->left, targetSum,ans, result);
        solve(root->right, targetSum,ans, result);
    }
     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<int>ans;
        solve(root, targetSum, ans, result);
        return result;
    }
    
};