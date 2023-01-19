class Solution {
public:
    //6. Making findparent function 
    int findParent(int node, vector<int>&parent){
        //If it's own parent 
        if(node == parent[node]){
            return node;
        }
        //Make the tree its parent => Path Compression 
        return parent[node]=findParent(parent[node],parent);
    }
    //5. Making up the union function 
    void Union(int u,int v, vector<int >&parent, vector<int> &rank){
        //Find their parent 
        u=findParent(u, parent);
        v=findParent(v, parent);
        //If the rank of one is greater than other then make it parent 
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
        //This is a DFS Union Find Question
        //It's used to find the number of connected memebers 
        //Ever single node is condidered to be connected to itself
        //Thus the maximum nodes connected is the size itself
        
        //Algorithm 
        //1. Make up the parent array 
        int N = isConnected.size();
        vector<int>parent(N);
        for(int i=0;i<N;i++){
            parent[i]=i;
        }
        //2. Make up a rank array and initalise everything with 0
        vector<int>rank(N,0);
        //3. If they are connected then call the union function 
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(isConnected[i][j]==1){
                    Union(i, j, parent, rank);
                }
            }
        }
        //4. If i is the parent of ith element then increment the count 
        int count =0;
        for(int i=0;i<N;i++){
            if(i==parent[i]){
                count++;
            }
        }
        return count;
    }
};