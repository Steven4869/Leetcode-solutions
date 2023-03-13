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
    //For this we'll check three conditions     
    //Root node should be equal
    //left subtree of left node should be equal to rigth subtree of right node 
    // right subtree of right node should be equal to left subtree of right node
    
    
    bool isMirror(TreeNode *root1, TreeNode *root2){
        //If both the roots are NULL return true
        if(root1==NULL && root2==NULL)
            return true;
        //Root node should be equal
        if(root1!=NULL && root2!=NULL && root1->val==root2->val){
            return isMirror(root1->left, root2->right)&&isMirror(root1->right, root2->left);
        }
        return false;

    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
        
    }
};