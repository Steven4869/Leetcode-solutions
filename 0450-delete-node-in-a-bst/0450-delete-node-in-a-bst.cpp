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
    TreeNode *minVal(TreeNode *root){
        TreeNode *temp = root;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //Three choices
        //Deleeting the leaf node 
        //Deleting the one child node 
        //Deleting node with two child node 
        
        if(root==NULL){
            return root;
        }
        if(root->val == key){
            //Node with 0 child 
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            
            //Node with 1 child node 
            //For the left child node 
            if(root->left!=NULL && root->right == NULL){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            //For the right child node 
            if(root->left == NULL && root->right !=NULL){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            //For the node with 2 child nodes 
            if(root->left !=NULL && root->right !=NULL){
                int mini = minVal(root->right)->val;
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }
        }
        else if(root->val>key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else{
            root->right = deleteNode(root->right, key);
            return root;
        }
        return root;
    }
};