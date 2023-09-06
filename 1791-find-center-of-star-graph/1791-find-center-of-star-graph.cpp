class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adjList;
        for(const auto&edge:edges){
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int>result(edges.size()+2,0);
        
        for(int i=1;i<=edges.size()+2;i++){
            for(const auto &it:adjList[i]){
                result[it]++;
            }
        }
        
        for(int i=1;i<=edges.size()+2;i++){
            if(result[i] == edges.size())
                return i;
        }
        return -1;
    }
};