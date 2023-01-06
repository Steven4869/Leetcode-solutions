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
    vector<vector<int>>result;
    void dfs(TreeNode *root, int level){
        if(!root)
            return;
        if(result.size()==level){
            result.push_back({});
        }
        result[level].push_back(root->val);
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        //Recursive approach using DFS
        dfs(root, 0);
        return result;
        
    }
};