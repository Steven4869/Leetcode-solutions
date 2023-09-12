class Solution {
public:
     bool bfs(int node, unordered_map<int, list<int>>& adjList, vector<int>& colors) {
        queue<int> q;
        colors[node] = 1;
        q.push(node);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adjList[u]) {
                if (colors[v] == 0) {
                    colors[v] = (colors[u] == 1) ? 2 : 1;
                    q.push(v);
                } else if (colors[u] == colors[v]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, list<int>>adjList;
        for(const auto &edge:dislikes){
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int>colors(n+1, 0);
        for(int i=1;i<=n;i++){
            if(colors[i] == 0){
                if(bfs(i, adjList, colors) == false)
                    return false;
            }
        }
        
        return true;
    }
};