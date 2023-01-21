class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x = jug1Capacity;
        int y = jug2Capacity;
        int z = x+y;
        
        vector<int>visited(z+1, 0);
        queue<int>q;
        int dir[]={-x,x,y,-y};
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            if(node == targetCapacity)
                return true;
            
            for(int i=0;i<4;i++){
                int newNode = node + dir[i];
                if(newNode>=0&&newNode<=z&&visited[newNode]==0){
                    q.push(newNode);
                    visited[newNode]=1;
                }
            }
        }
        return false;
        
    }
};