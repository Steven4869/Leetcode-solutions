class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        //Create the Adjacency List and store the dregee for each edge 
        unordered_map<int, list<int>>adjList;
        vector<int>degree(n, 0);
        
        for(const auto&edge:edges){
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            
            degree[u]++;
            degree[v]++;
            
        }
        
        //Making up the queue and inserting only those whose degree is 1 
        queue<int>q;
        vector<int>result;
        for(int i=0;i<n;i++){
            if(degree[i]==1)
                q.push(i);
        }
        //Perfrom the BFS for the degree 1 and keep on decrementing it for each degree in the adjacency 
        
        while(!q.empty()){
            int size = q.size();
            result.clear();
            while(size--){
                int frontNode = q.front();
                q.pop();
                result.push_back(frontNode);
                
                for(const auto& neighbor:adjList[frontNode]){
                    degree[neighbor]--;
                    
                    if(degree[neighbor]==1){
                        q.push(neighbor);
                    }
                }
            }
        }
        return result;
    }
};