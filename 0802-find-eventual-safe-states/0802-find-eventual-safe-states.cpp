class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //Creating Adjacency List 
        unordered_map<int, list<int>>adjList;
        vector<int>outdegree(graph.size());
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            for(int neighbor:graph[i]){
                adjList[neighbor].push_back(i);
                outdegree[i]++;
            }
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int>safe;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            safe.push_back(front);
            for(auto neighbors:adjList[front]){
                outdegree[neighbors]--;
                if(outdegree[neighbors]==0){
                    q.push(neighbors);
                }
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};