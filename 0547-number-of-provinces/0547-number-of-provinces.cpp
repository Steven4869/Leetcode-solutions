class Solution {
public:
    void dfs(int node, vector<int>&visited,vector<vector<int>>& isConnected){
        visited[node]=1;
        
        for(int neighbor = 0;neighbor<isConnected.size();neighbor++){
            if(!visited[neighbor] && isConnected[node][neighbor]==1)
                dfs(neighbor, visited, isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n = isConnected.size();
        int count = 0;
        vector<int>visited(n, 0);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, visited, isConnected);
                count++;
            }
        }
        return count;
    }
};