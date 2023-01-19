class Solution {
public:
    
    //DFS Function 
    void dfs(vector<vector<int>>& rooms, vector<bool> &visited, int source){
        //Mark it as visited 
        visited[source]=true;
        //Traverse the graph 
        for(int i=0;i<rooms[source].size();i++){
            //Check if it's visited or not 
            if(!visited[rooms[source][i]]){
                //Call the dfs function 
                dfs(rooms, visited, rooms[source][i]);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //This is simple DFS Traversal 
        //We'll have a visited array to check if we have visited or not 
        //Algorithm 
        //1. Make a visited array 
        vector<bool>visited(rooms.size(),false);
        //2. Call the dfs function 
        dfs(rooms, visited, 0);//0 refers to source node 
        //3. Traverse the visited array if everything is visited then mark true 
        for(int i=0;i<rooms.size();i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};