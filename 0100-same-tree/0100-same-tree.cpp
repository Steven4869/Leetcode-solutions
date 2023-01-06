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
    //Iterative Apporach 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //Intialise Queue to store elements 
        queue<TreeNode *>qu;
        //Push both p and q into queue 
        qu.push(p);
        qu.push(q);
        //run the loop until queue is empty 
        while(!qu.empty()){
            //Intialise the front node 
            p = qu.front();
            qu.pop();
            
            q = qu.front();
            qu.pop();
            
            //Check the cases 
            if(p==NULL&&q==NULL)
                continue;
            if(p==NULL||q==NULL||p->val!=q->val)
                return false;
            //Insert the right and left nodes into queue 
            qu.push(p->left);
            qu.push(q->left);
            
            qu.push(p->right);
            qu.push(q->right);
        }
        return true;
    }
};