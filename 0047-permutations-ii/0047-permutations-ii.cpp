class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>curr;
        unordered_map<int,int>mp;
        
        for(int num:nums){
            mp[num]++;
        }
        
        solve(nums, result, curr, mp);
        return result;
    }
    void solve(vector<int>&nums, vector<vector<int>>&result, 
              vector<int>&curr, unordered_map<int,int>&mp){
        if(curr.size() == nums.size()){
            result.push_back(curr);
            return;
        }
        
        for(const auto &entry:mp){
            int num = entry.first;
            int freq = entry.second;
            
            if(freq>0){
                curr.push_back(num);
                mp[num]--;
                solve(nums, result, curr, mp);
                curr.pop_back();
                mp[num]++;
            }
        }

    }
};