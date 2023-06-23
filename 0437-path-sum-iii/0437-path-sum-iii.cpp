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
    void solve(TreeNode *root, int targetSum, int &count, vector<int>&ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        solve(root->left, targetSum, count, ans);
        solve(root->right, targetSum, count, ans);
        long long sum = 0;
        for(int i=ans.size()-1;i>=0;i--){
            sum = sum + ans[i];
            if(sum==targetSum){
                count++;
            }
        }
        ans.pop_back();
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        vector<int>ans;
        solve(root, targetSum, count, ans);
        return count;
    }
};