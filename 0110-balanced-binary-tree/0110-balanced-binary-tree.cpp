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
    //Approach 
    //For a Balanced Binary Tree the difference of height between left and right must be 
    //less than 1 and both left and right should exist
    int height(TreeNode *root){
        if(root==NULL)
            return NULL;
        int left = height(root->left);
        int right = height(root->right);
        return max(right, left)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(abs(leftHeight-rightHeight)<=1&&isBalanced(root->left)&&isBalanced(root->right))
            return true;
        return false;
    }
};