class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //Base Case 
        if(n==1)
            return {0};
        //Create the Adjacency List 
        unordered_map<int, list<int>>adjList;
        vector<int>degree(n, 0);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            
            degree[u]++;
            degree[v]++;
        }
        //Making the queue and pushing all the nodes with degree 1 
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==1)
                q.push(i);
        }
        vector<int>res;
        
        while(!q.empty()){
            int size = q.size();
            res.clear();
            while(size--){
                int frontNode = q.front();
                q.pop();
                res.push_back(frontNode);
                for(auto i:adjList[frontNode]){
                    degree[i]--;
                    if(degree[i]==1)
                        q.push(i);
                    
                }
            }
        }
        return res;
    }
};