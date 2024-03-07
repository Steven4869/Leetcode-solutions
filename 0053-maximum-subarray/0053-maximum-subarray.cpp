class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int maxi= arr[0];
        int n= arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum = sum + arr[i];
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                sum =0;
            }
        }
        return maxi;
    }
};