class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        const double INF = 1e9;
        
        //Making the adjList 
        unordered_map<int, vector<pair<int,double>>>adjList;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            
            adjList[u].emplace_back(v, w);
            adjList[v].emplace_back(u, w);
        }
        
        //Making up the prirority queue 
        priority_queue<pair<double,int>>pq;
        pq.push({0.0, start_node});
        vector<double>dist(n, -INF);
        dist[start_node]=0.0;
        
        while(!pq.empty()){
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(prob>dist[node])
                continue;
            
            for(const auto&neighbor:adjList[node]){
                int nextNode = neighbor.first;
                double nextProb = prob + log(neighbor.second);
                
                if(nextProb>dist[nextNode]){
                    dist[nextNode]=nextProb;
                    pq.push({nextProb, nextNode});
                }
            }
        }
        
        if(dist[end_node] == -INF)
            return 0.0;
        
        return exp(dist[end_node]);
    }
};