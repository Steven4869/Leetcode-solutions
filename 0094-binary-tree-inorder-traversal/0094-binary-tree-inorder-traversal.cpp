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
    void solve(TreeNode *root, vector<int>&result){
        if(root==NULL){
            return;
        }
        solve(root->left, result);
        result.push_back(root->val);
        solve(root->right, result);
    }
    void solveStack(TreeNode *root, vector<int>&result){
        stack<TreeNode*>st;
        TreeNode *curr = root;
        while(curr!=NULL || !st.empty()){
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            result.push_back(curr->val);
            st.pop();
            if(curr!=NULL){
                curr=curr->right;
            }
        }
    }
    void morrisTraversal(TreeNode *root, vector<int>&result){
        //Make the current node point to the root
        TreeNode *curr = root;
        //Check if the left subtree is null or not 
        while(curr!=NULL){
            if(curr->left==NULL){
                //Then print the data and point to the right 
                result.push_back(curr->val);
                curr=curr->right;
            }
            else{
                //Find the rightmost node of the left node 
                TreeNode *pre = curr->left;
                //Traverse until we find the rightmost node and it                  is not equal to the current 
                while(pre->right!=NULL && pre->right!=curr){
                    pre=pre->right;
                }
                //If the right node is NULL then make up the temp                      link
                if(pre->right==NULL){
                    pre->right = curr;
                    curr=curr->left;
                }
                //Otherwise remove the link and move to the right
                else{
                    pre->right=NULL;
                    result.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>result;
        // solve(root, result);
        // solveStack(root, result);
        morrisTraversal(root, result);
        return result;
    }
};