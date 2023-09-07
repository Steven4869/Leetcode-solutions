class Solution {
public:
    int findParent(vector<int>&parent, int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent, parent[node]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int>parent(n+1, -1);
        
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        vector<int>result;
        for(const auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            
            int parentU = findParent(parent, u);
            int parentV = findParent(parent, v);
            
            //If they have same parent then that's the redundant edge 
            if(parentU == parentV){
                result=edge;
            }
            else
                parent[parentU]=parentV;
        }
        return result;
        
    }
};