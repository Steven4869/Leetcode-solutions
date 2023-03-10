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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *>q;
        vector<vector<int>>result;
        
        if(root==NULL)
            return result;
        
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>ans;
            for(int i=0;i<n;i++){
                TreeNode *temp = q.front();
                q.pop();
                
                ans.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            result.push_back(ans);
        }
        return result;
    }
};