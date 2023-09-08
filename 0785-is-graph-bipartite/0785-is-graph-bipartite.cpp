class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colors(n, 0);
        //Traversing the graph 
        for(int i=0;i<n;i++){
            if(colors[i])
                continue;
            queue<int>q;
            q.push(i);
            colors[i]=1;
            while(!q.empty()){
                int parent = q.front();
                q.pop();
                
                for(auto child:graph[parent]){
                    if(colors[child]==0){
                        colors[child]=-colors[parent];
                        q.push(child);
                    }
                    else{
                        if(colors[child]==colors[parent])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};