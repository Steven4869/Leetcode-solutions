/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findDistanceNodes(TreeNode *root, int K, unordered_map<TreeNode*, TreeNode*>&parentMap, unordered_set<TreeNode*>&visit, vector<int>&result){
         if(visit.find(root)!=visit.end())
            return;
        visit.insert(root);
        if(K==0){
            result.push_back(root->val);
            return;
        }
        if(root->left!=NULL)
            findDistanceNodes(root->left, K-1, parentMap, visit, result);
        if(root->right!=NULL)
            findDistanceNodes(root->right, K-1, parentMap, visit, result);
        if(parentMap[root]!=NULL)
            findDistanceNodes(parentMap[root], K-1, parentMap, visit, result);
    }
    void buildParentMap(TreeNode *root, unordered_map<TreeNode*, TreeNode*>&parentMap){
        if(root==NULL)
            return;
        if(root->left!=NULL){
            parentMap[root->left]=root;
            buildParentMap(root->left, parentMap);
        }
        if(root->right!=NULL){
            parentMap[root->right]=root;
            buildParentMap(root->right, parentMap);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*>parentMap;
        unordered_set<TreeNode*>visit;
        buildParentMap(root, parentMap);
        vector<int>result;
        findDistanceNodes(target, K, parentMap, visit,result);
        return result;
    }
};