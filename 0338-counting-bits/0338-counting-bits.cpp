class Solution {
public:
    vector<int> countBits(int n) {
        //Idea is that the answer is same for the n=3 and n=5 
        //In  a similar way answer is same for the n =2 and n=4
        //So we can make up a recursive funtion 
        //For even it'll simply be n/2 whereas for odd it's 1+n/2
        
        vector<int>result(n+1);
        for(int i=0;i<=n;i++)
            result[i]=solve(i);
        return result;
    }
    int solve(int n){
        //Base condition 
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n%2==0)
            return solve(n/2);
        else{
            return 1+solve(n/2);
        }
    }
};