class Solution {
public:
    int solveBS(vector<int> result){
        //Base Case 
        if(result.size()==0)
            return 0;
        
        vector<int>ans;
        ans.push_back(result[0]);
        for(int i=1;i<result.size();i++){
            if(result[i]>ans.back()){
                ans.push_back(result[i]);
            }
            else{
                int index = lower_bound(ans.begin(), ans.end(), result[i]) - ans.begin();

                ans[index]=result[i];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //Sort based on the widths in increasing order, if the widths are equal then 
        //sort it based on the height in decreasing order 
        
        sort(envelopes.begin(), envelopes.end(), [](const auto&a, const auto&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        vector<int>result;
        for(int i=0;i<envelopes.size();i++){
            result.push_back(envelopes[i][1]);
        }
        return solveBS(result);
        
    }
};