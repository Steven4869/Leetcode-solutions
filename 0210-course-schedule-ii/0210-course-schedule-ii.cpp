class Solution {
public:
    bool cycle;
    void dfs(unordered_map<int,list<int>>&adjList, vector<int>&visited, stack<int>&st, int node, vector<int>&parent){
        if(cycle)
            return;
        visited[node]=1;
        parent[node]=1;
        for(auto neighbours:adjList[node]){
            if(parent[neighbours]==1)
                cycle=true;
            if(!visited[neighbours]){
                dfs(adjList,visited,st,neighbours,parent);
            }
        }
        st.push(node);
        parent[node]=0;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Creating a Adjacency List 
        unordered_map<int,list<int>>adjList;
        int edges = prerequisites.size();
        for(int i=0;i<edges;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adjList[u].push_back(v);
    
        }
    
    //Creating a visited array, stack, parent array and cycle detection 
    vector<int>visited(numCourses, 0);
    stack<int>st;
    vector<int>parent(numCourses, 0);
    cycle = false;
    for(int i=0;i<numCourses;i++){
        if(!visited[i]){
            dfs(adjList, visited, st, i, parent);
        }
    }
    
    //To store the result
    vector<int>result;
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
        if(cycle)
            return {};
        reverse(result.begin(),result.end());
        return result;
    }
};