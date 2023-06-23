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
    void solve(TreeNode *root, int targetSum, vector<int>& ans, vector<vector<int>>& result) {
        if (root == nullptr) {
            return;
        }
        
        ans.push_back(root->val);
        
        if (targetSum == root->val && root->left == nullptr && root->right == nullptr)          {
            result.push_back(ans);
        }
        
        solve(root->left, targetSum - root->val, ans, result);
        solve(root->right, targetSum - root->val, ans, result);
        
        ans.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> ans;
        solve(root, targetSum, ans, result);
        return result;
    }
};