class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        //It's a Bi directional BFS Question 
        //We'll first mark the forbidden jumps in the visited 
        // We can jump forward and backward
        //Perform BFS accordingly 
        
        //algorithm 
        //Make up the visited map and queue 
        unordered_map<int,int>visited;
        //Insert the forbidden elements into the map 
        for(auto i:forbidden){
            visited[i]=true;
        }
        
        //Make up a queue 
        queue<pair<int,int>>q;
        //Push the first position into queue 
        q.push({0,0});
        int result =0;
        //Perform BFS 
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                pair<int,int>curr=q.front();
                q.pop();
                int num = curr.first;
                if(num==x)
                    return result;
                if(visited[num]==true)
                    continue;
                visited[num]=true;
                if(curr.second==0&&num-b>=0){
                    q.push({(num-b), 1});
                }
                if(num<=2000+b){
                    q.push({(num+a),0});
                }
                
            }
            result++;
        }
        return -1;
    }
};