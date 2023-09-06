class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, list<int>>adjList;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        //Perform BFS
        vector<int>visited(n, 0);
        queue<int>q;
        q.push(source);
        visited[source]=1;
        
        while(!q.empty()){
            int currentNode = q.front();
            q.pop();
            
            if(currentNode == destination)
                return true;
            
            for(const auto &i:adjList[currentNode]){
                if(!visited[i]){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
        return false;
    }
};