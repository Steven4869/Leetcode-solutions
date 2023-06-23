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
    bool hasPathSum(TreeNode* root, int targetSum) {
        //Check if the right, left subtree are true and root->data is equal to 
        //target sum 
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL&&root->val==targetSum){
            return true;
        }
        bool leftAns = hasPathSum(root->left, targetSum-root->val);
        bool rightAns = hasPathSum(root->right, targetSum-root->val);
        return leftAns||rightAns;
    }
};