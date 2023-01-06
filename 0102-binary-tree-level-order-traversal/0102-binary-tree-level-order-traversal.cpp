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
        //Iterative using BFS
        //Intialise queue 
        queue<TreeNode *>q;
        //Intialise the result vector to store the final result
        vector<vector<int>>result;
        //Base condition 
        if(root==NULL)
            return result;
        //Insert root node into queue 
        q.push(root);
        //Run the loop until queue is empty 
        while(!q.empty()){
            // Check the size of the queue 
            int n = q.size();
            //Make the answer vector to store the level elements into that vector 
            vector<int>ans;
            //Run the loop till the size 
            for(int i=0;i<n;i++){
                //Assign the temp value 
                TreeNode *temp = q.front();
                //Pop the value from the queue 
                q.pop();
                
                //Insert the answer into queue
                ans.push_back(temp->val);
                
                //Check for the left and right 
                //Check if the left or right of temp exists or not 
                //If exists then insert into queue 
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            //Store the answer into result 
            result.push_back(ans);
        }
        return result;
    }
};