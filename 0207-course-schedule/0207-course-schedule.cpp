class Solution {
public:
    
    void dfs(unordered_map<int,list<int>>&adjList, vector<int>&visited, stack<int>&st, int node){
        //Mark the visited node 
        visited[node]=1;
        //Check for the neighbours of the node 
        for(auto neighbours:adjList[node]){
            //If they are not visited call it recursivley 
            if(!visited[neighbours])
                dfs(adjList,visited,st,neighbours);
        }
        //Important step
        st.push(node);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //This problem is based on Topological Sorting 
        //How? u->v here u comes before v 
        //We have to check whether cycle exists or not, if cycle exists then print false 
        
        //Create an adjacency List 
        unordered_map<int,list<int>>adjList;
        //Push the elements 
        int edges = prerequisites.size();
        for(int i=0;i<edges;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adjList[u].push_back(v);
        }
        //Making a DFS Call 
        //Intialising the visited array, stack
        vector<int>visited(numCourses, 0);
        stack<int>st;
        for(int i=0;i<numCourses;i++){
            //If it's not visited then make the call 
            if(!visited[i]){
                dfs(adjList,visited,st,i);
            }
        }
        //Checking the count of the list
        vector<int>Topo(numCourses);
        int count=0;
        while(!st.empty()){
            Topo[st.top()]=count++;
            st.pop();
        }
        //Making up the result 
        for(int i=0;i<numCourses;i++){
            for(auto it:adjList[i]){
                if(Topo[i]>=Topo[it])
                    return false;
            }
        }
        return true;
    }
};