class Solution {
public:
    int GCD(int a, int b){
        if(b==0)
            return a;
        return GCD(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        int mn=nums[0];
        int mx=nums[0];
        for(int i=1;i<nums.size();i++){
            if(mn>nums[i])
                mn=nums[i];
            if(mx<nums[i])
                mx=nums[i];
        }
        return GCD(mn, mx);
    }
};