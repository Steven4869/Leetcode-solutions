class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });
        
        int chainLength = 1;
        int currentEnd = pairs[0][1];
        
        for(int i=0;i<pairs.size();i++){
            if(pairs[i][0]>currentEnd){
                chainLength++;
                currentEnd = pairs[i][1];
            }
        }
        return chainLength;
        
    }
};