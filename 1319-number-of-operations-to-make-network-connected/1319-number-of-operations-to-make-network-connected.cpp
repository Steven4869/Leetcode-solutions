class Solution {
public:
    //findParent function 
    int findParent(vector<int>&parent, int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findParent(parent, parent[node]);
    }
    //Union function 
    void Union(vector<int> &parent, vector<int> &rank, int u, int v){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        //This is Union Find DFS Question 
        
        //Algorithm 
        //1. Make the parent and rank array 
        int N = connections.size();
        
        if(n-1 > N){
            return -1;
        }
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        vector<int>rank(n,0);
        
        //If the parent of 1 connection is not the other then union it 
        for(int i=0;i<N;i++){
            if(findParent(parent, connections[i][0])!=findParent(parent,connections[i][1])){
                Union(parent, rank, connections[i][0], connections[i][1]);
            }
        }
        //If the element is its parent then increment the count 
        int count=0;
        for(int i=0;i<n;i++){
            if(i==parent[i]){
                count++;
            }
        }
        return count-1;
    }
};