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
    int solveBFS(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int level = 0;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            level++;
            for(int i=0;i<size;i++){
                TreeNode *frontNode = q.front();
                q.pop();
                
                if(frontNode->left)
                    q.push(frontNode->left);
                if(frontNode->right)
                    q.push(frontNode->right);
                if(frontNode->left==NULL && frontNode->right == NULL){
                    return level;
                }
            }
        }
        return level;
    }
    int minDepth(TreeNode* root) {
        return solveBFS(root);
    }
};