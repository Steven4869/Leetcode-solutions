class Solution {
public:
    int findParent(vector<int>&parent, int node){
        //If the parent is its own node then return the node 
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent, parent[node]);
    }
    void Union(int u, int v, vector<int>&parent, vector<int>&rank){
        //We need to find the parent node of i and j
        u = findParent(parent, u);
        v = findParent(parent, v);
        
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n = isConnected.size();
        //Create parent and rank array 
        vector<int>parent(n);
        vector<int>rank(n, 0);
        
        //Make the parent of every node its own 
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        //Make up the Union operation where it's connected
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j] == 1)
                    Union(i, j, parent, rank);
            }
        }
        
        //Counting the provinces 
        int count = 0;
        for(int i=0;i<n;i++){
            if(i == parent[i])
                count++;
        }
        return count;
    }
};