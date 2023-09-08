class Solution {
public:
    void dfs(int node, vector<vector<int>>&result, vector<int>&path,vector<vector<int>>& graph){
        path.push_back(node);
        if(node == graph.size()-1)
            result.push_back(path);
        else{
            for(const auto &neighbor:graph[node]){
                dfs(neighbor,result, path, graph);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>result;
        vector<int>path;
        
        dfs(0, result, path, graph);
        return result;
    }
};