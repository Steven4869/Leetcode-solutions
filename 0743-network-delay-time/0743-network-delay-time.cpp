class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1, INT_MAX);
        
        // creating adjacency List 
        unordered_map<int, vector<pair<int,int>>>graph;
        
        //Inseting values 
        for(const auto&time:times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            
            graph[u].emplace_back(v,w);
        }
        
        // Priority Queue in ascending order 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        //Making the kth node to be zero 
        dist[k]=0;
        pq.emplace(0,k);
        
        //Running the algorithm 
        
        while(!pq.empty()){
            int currDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if(currDist>dist[u]){
                continue;
            }
            
            for(const auto &neighbor:graph[u]){
                int v = neighbor.first;
                int w = neighbor.second;
                
                if(currDist + w <dist[v]){
                    dist[v] = currDist + w;
                    pq.emplace(dist[v],v);
                }
            }
        }
        
        int maxTime = *max_element(dist.begin()+1, dist.end());
        return (maxTime == INT_MAX)?-1:maxTime;
    }
};