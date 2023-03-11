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
    TreeNode *solve(vector<int>&nums, int left, int right){
        if(left>right)
            return NULL;
        //Getting the root node 
        int mid = (right-left)/2 + left;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = solve(nums, left, mid-1);
        root->right = solve(nums, mid+1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        return solve(nums, left, right);
    }
};