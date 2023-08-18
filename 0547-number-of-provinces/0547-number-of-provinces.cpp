class Solution {
public:
    
    int findParent(vector<int>&parent, int node){
        if(parent[node] == node)
            return node;
        return parent[node]=findParent(parent, parent[node]);
    }
    void Union(int u, int v, vector<int>&parent, vector<int>&rank){
        u = findParent(parent, u);
        v = findParent(parent, v);
        
        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[u]>rank[v])
            parent[v]=u;
        else{
            parent[u]=v;
            rank[u]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        //Creating a parent and rank array 
        vector<int>parent(n);
        vector<int>rank(n, 0);
        
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j] == 1){
                    Union(i,j,parent,rank);
                }
            }
        }
        
        int count = 0;
        for(int i=0;i<n;i++){
            if(i == parent[i])
                count++;
        }
        return count;
    }
};