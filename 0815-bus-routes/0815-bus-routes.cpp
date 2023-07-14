class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //If the source is the target then return 0 
        if(source == target)
            return 0;
        
        //Creating a graph 
        unordered_map<int, list<int>>graph;
        for(int i=0;i<routes.size();i++){
            for(int stop:routes[i]){
                graph[stop].push_back(i);
            }
        }
        //Making up the visited array 
        vector<bool>visited(routes.size(), false);
        //Applying BFS to find the minimum number of bus stop 
        queue<int>q;
        q.push(source);
        int busChanges=0;
        while(!q.empty()){
            int size = q.size();
            busChanges++;
            while(size--){
                int frontStop = q.front();
                q.pop();
                
                for(int route:graph[frontStop]){
                    if(visited[route])
                        continue;
                    visited[route]=true;
                    
                    for(int nextStop:routes[route]){
                        if(nextStop == target)
                            return busChanges;
                        q.push(nextStop);
                    }
                }
            }
        }
        return -1;
    }
};