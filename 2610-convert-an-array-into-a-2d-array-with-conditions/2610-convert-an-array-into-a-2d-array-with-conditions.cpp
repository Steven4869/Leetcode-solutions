class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        //Make a map and store the occurences 
        unordered_map<int,int>mp;
        int maxLength = 0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            maxLength = max(maxLength, mp[nums[i]]);
        }
        
        vector<vector<int>>result(maxLength);
        for(auto it:mp){
            for(int i=0;i<it.second;i++){
                result[i].push_back(it.first);
            }
        }
        return result;
        
    }
};