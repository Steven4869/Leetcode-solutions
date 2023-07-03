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
    void createMapping(map<int,int>&nodeToIndex, vector<int>&inorder, int n){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
    }
    TreeNode *solve(vector<int>&inorder, vector<int>&postorder, int &postorderIndex, map<int,int>&nodeToIndex, int inorderStart, int inorderEnd, int n){
        if(postorderIndex<0 || inorderStart>inorderEnd){
            return NULL;
        }
        int element = postorder[postorderIndex--];
        TreeNode *root = new TreeNode(element);
        int position = nodeToIndex[element];
        
        root->right = solve(inorder, postorder, postorderIndex, nodeToIndex, 
                           position+1, inorderEnd, n);
        
        root->left = solve(inorder, postorder, postorderIndex, nodeToIndex, 
                           inorderStart, position-1, n);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        map<int,int>nodeToIndex;
        int postorderIndex = n-1;
        createMapping(nodeToIndex, inorder, n);
        TreeNode * ans = solve(inorder, postorder, postorderIndex, nodeToIndex,
                              0, n-1, n);
        return ans;
    }
};

