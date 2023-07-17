class Solution {
public:
    int findParent(vector<int>&parent, int node){
        //If parent is its own node 
        if(parent[node]==node)
            return node;
        return parent[node] = findParent(parent, parent[node]);
    }
    void unionSet(int u, int v, vector<int>&parent, vector<int>&rank){
        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[u]>rank[v])
            parent[v]=u;
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        
        //Make the parent and rank arrays 
        vector<int>parent(n);
        vector<int>rank(n, 0);
        
        //Make the parent of each node its own 
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        int extraConnections = 0;
        
        for(auto &con:connections){
            int u = con[0];
            int v = con[1];
            
            int parentU = findParent(parent, u);
            int parentV = findParent(parent, v);
            
            if(parentU != parentV)
                unionSet(parentU, parentV, parent, rank);
            else
                extraConnections++;
        }
        
        int numComponents = 0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                numComponents++;
            }
        }
        
        int numOperations = numComponents -1;
        if(extraConnections < numOperations)
            return -1;
        return numOperations;
    }
};