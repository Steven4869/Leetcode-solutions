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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>result;
        // solve(root, result);
        solveStack(root, result);
        return result;
    }
};