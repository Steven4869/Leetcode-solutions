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
    vector<int>result;
    int minDiffInBST(TreeNode* root) {
        
        if(root!=NULL){
            minDiffInBST(root->left);
            result.push_back(root->val);
            minDiffInBST(root->right);
        }
        
        int temp = INT_MAX;
        for(int i=1;i<result.size();i++){
            temp=min(temp, result[i]-result[i-1]);
        }
        return temp;
    }
};