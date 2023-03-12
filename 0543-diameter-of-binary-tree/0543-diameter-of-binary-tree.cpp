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
   int result=0;
    int dfs(TreeNode *root){
        if(root==NULL)
            return 0;
        int lheight=dfs(root->left);
        int rheight=dfs(root->right);
        result=max(result, lheight+rheight);
        return 1+max(lheight,rheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        dfs(root);
        return result;
    }
};