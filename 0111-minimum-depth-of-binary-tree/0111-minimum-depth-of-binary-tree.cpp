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
    int solve(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int leftNode = solve(root->left);
        int rightNode = solve(root->right);
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        if(root->left == NULL){
            return 1 + rightNode;
        }
        if(root->right == NULL){
            return 1 + leftNode;
        }
        return min(leftNode, rightNode) + 1;
    }
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};