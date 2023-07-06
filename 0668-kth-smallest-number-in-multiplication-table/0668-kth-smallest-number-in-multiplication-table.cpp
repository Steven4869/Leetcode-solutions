class Solution {
public:
    int solve(int m, int n, int mid){
        int ans = 0;
        //Traverse the entire column
        for(int i=1;i<=m;i++){
            ans = ans + min(n, mid/i); 
        }
        return ans;
    }
    int findKthNumber(int m, int n, int k) {
        //Lower Bound Question of BS
        int start = 1;
        int end = m*n;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(solve(n,m,mid)<k){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return start;
    }
};