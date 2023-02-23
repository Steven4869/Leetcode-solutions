class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int count=0;
        for(auto i:nums){
            count=count^i;
        }
        
        int mask=1;
        while(1){
            if((mask&count)==0){
                mask=mask<<1;
            }
            else{
                break;
            }
        }
        int a=0, b=0;
        for(int i=0;i<nums.size();i++){
            if((mask&nums[i])){
                a=a^nums[i];
            }
            else{
                b=b^nums[i];
            }
        }
        return {a,b};
    }
    
};