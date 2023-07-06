class Solution {
public:
    int mySqrt(int x) {
        long long start =0, end =x;
        long long ans =-1;
        long long mid = start + (end-start)/2;
        while(start<=end){
            long long sq = mid*mid;
            if(sq==x){
                return mid;
            }
            else if(sq<x){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
};