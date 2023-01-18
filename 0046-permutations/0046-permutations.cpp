class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //BACKTRACKING question
        
        vector<vector<int>>result;
        vector<int>current;
        vector<bool>isVisited(nums.size(), false);
        backtrack(nums, result, current, isVisited);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<vector<int>> &result, vector<int> &current, vector<bool> &isVisited){
        //If it reaches to the bottom then insert it to the result vector
        if(current.size()==nums.size()){
            result.push_back(current);
        }
        else{
            for(int i=0;i<nums.size();i++){
                //If the current vector contains the number or not
                if(isVisited[i])
                    continue;
                isVisited[i]=true;
                current.push_back(nums[i]);
                backtrack(nums,result,current, isVisited);
                current.pop_back();
                isVisited[i]=false;
            }
        }
    }
};