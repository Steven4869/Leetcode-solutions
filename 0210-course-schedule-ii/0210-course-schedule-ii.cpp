class Solution {
public:
    //In this question, we need to check for the cycle too 
    //If we print topological sort, then we might miss on the cycle detection
    bool cycle;
    void dfs(unordered_map<int, list<int>> &adjList, vector<int>&visited,                stack<int>&st,vector<int>&dfsVisited, int node){
        //Mark the node as visited 
        if(cycle){
            return;
        }
        visited[node]=1;
        dfsVisited[node]=1;
        //Traverse its neighbours 
        for(auto i:adjList[node]){
            //If not visited then call the dfs 
            if(dfsVisited[i]==1){
                cycle = true;
            }
            if(!visited[i]){
                dfs(adjList, visited, st, dfsVisited, i);
            }
        }
        st.push(node);
        dfsVisited[node]=0;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Prpeare an Adjacency List 
        
        unordered_map<int, list<int>>adjList;
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adjList[u].push_back(v);
        }
        
        //Creating varaibles for Topo Sort 
        
        vector<int>visited(numCourses, 0);
        stack<int>st;
        vector<int>dfsVisited(numCourses, 0);
        cycle = false;
        for(int i=0;i<numCourses;i++){
            //If not visited then call the dfs 
            if(!visited[i]){
                dfs(adjList, visited, st, dfsVisited, i);
            }
        }
        vector<int>result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        if(cycle){
            return {};
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};