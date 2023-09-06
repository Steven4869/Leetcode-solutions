class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //Approach
        //We need to maintain a vector where the edge going towards will be incremenered while the other one will be decremented 
        //Then traverse it and if they happen to be N-1 this means we found the town judge 
        
//         vector<int> trustCount(n+1, 0);
        
//         for(const auto &t:trust){
//             trustCount[t[0]]--;
//             trustCount[t[1]]++;
//         }
        
//         for(int i=1;i<=n;i++){
//             if(trustCount[i]==n-1)
//                 return i;
//         }
//         return -1;
        
        //Another Approach is used to indegree and outdegree
        //If the outdegree is 0 and indegree is n-1 then that means town judge is found 
        
        vector<int>out(n+1, 0);
        vector<int>in(n+1, 0);
        
        for(const auto edge:trust){
            out[edge[0]]--;
            in[edge[1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(out[i]==0 && in[i]==n-1)
                return i;
        }
        
        return -1;
    }
};