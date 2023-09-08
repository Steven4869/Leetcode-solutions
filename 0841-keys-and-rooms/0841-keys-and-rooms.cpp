class Solution {
public:
    void dfs(int node, vector<int>&visited, vector<vector<int>>& rooms){
        visited[node]=1;
        
        for(const auto &neighbor:rooms[node]){
            if(!visited[neighbor]){
                dfs(neighbor, visited, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n, 0);
        
        dfs(0, visited, rooms);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};