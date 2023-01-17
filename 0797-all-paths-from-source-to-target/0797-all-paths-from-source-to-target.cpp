class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //This follows a backtracking approach 
        //That is travelling through each node then going back 
        //DFS Algorithm to be used 
        
        //we have to start from the 0th node and then go to other nodes 
        
        //Algorithm 
        //1. Intialise the vectors for result and current path 
        vector<vector<int>>result;
        vector<int>currentPath;
        
        dfs(graph, result, currentPath, 0); // 0 is the source, always the source
        return result;
        
    }
    
    void dfs(vector<vector<int>>& graph,  vector<vector<int>> &result,                                      vector<int> &currentPath, int source){
        //First push the source node 
        currentPath.push_back(source);
        
        //If the node is reached to last position then insert it into result 
        if(source==graph.size()-1){
            result.push_back(currentPath);
        }
        //Traversing the other items in dfs
        for(auto neighbours:graph[source]){
            dfs(graph, result, currentPath, neighbours);
        }
        //Backtrack the result
        currentPath.pop_back();
    }
};