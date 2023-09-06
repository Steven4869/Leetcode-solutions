class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>>adjList;
        vector<int>indegree(numCourses);
        for(const auto &edge:prerequisites){
            int u = edge[0];
            int v = edge[1];
            
            indegree[u]++;
            
            adjList[v].push_back(u);
        }
        vector<int>result;
        queue<int>q;
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            numCourses--;
            
            for(const auto &neighbor:adjList[frontNode]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        return numCourses==0;
        
    }
};