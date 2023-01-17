class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //It's a basic Backtracking question 
        
        //1. Intialise the result and current vector 
        vector<vector<int>>result;
        vector<int>current;
        
        //2. Call the backtrack function 
        backtrack(nums, result, current, 0);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>> &result, vector<int> &current, int                    source){
        //Add the node to the result
        result.push_back(current);
        
        //Traverse the neighbours elements 
        for(int i=source;i<nums.size();i++){
            //Insert it into current array 
            current.push_back(nums[i]);
            //Run the function 
            backtrack(nums, result, current, i+1);
            //Pop it from the array 
            current.pop_back();
        }
        
    }
};