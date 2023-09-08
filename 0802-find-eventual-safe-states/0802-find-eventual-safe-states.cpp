class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //This question is similar to the Topological sort 
        int n = graph.size();
        unordered_map<int, list<int>>adjList;
        vector<int>indegree(n,0);
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            for(const auto&neighbor:graph[i]){
                adjList[neighbor].push_back(i);
                indegree[i]++;
            }
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int>result;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            result.push_back(frontNode);
            
            for(const auto &neighbor:adjList[frontNode]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0)
                    q.push(neighbor);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};