class Solution {
public:
    int dp[20];
    int numTrees(int n) {
        // we are making the root node to be ith value then get the values of other nodes 
        // Trees[3] = Trees[0]*Trees[2]+Trees[1]*Trees[1]+Trees[2]*Trees[0]
        // Trees[2] = Trees[0]*Trees[1]+Trees[1]*Trees[0]
        // For a single node number of nodes can be only one 
        
        // if(n<=1)
        //     return 1;
        // int result =0;
        // for(int i=1;i<=n;i++){
        //     result = result + numTrees(i-1)*numTrees(n-i);
        // }
        // return result;
        //TC : O(N^N)
        //To optimise it we have to save the calss in the dp table 
        
        if(n<=1)
            return 1;
        if(dp[n])
            return dp[n];
        for(int i=1;i<=n;i++){
            dp[n]+=numTrees(i-1)*numTrees(n-i);
        }
        return dp[n];
     
    }
};