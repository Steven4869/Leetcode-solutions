class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //building up the comprator function 
        
        auto comp = [](const vector<int>&p1, const vector<int>&p2){
            return (p1[0]*p1[0] + p1[1]*p1[1])<(p2[0]*p2[0]+p2[1]*p2[1]);
        };
        
        //Creating Max Heap for closest points with comprator function 
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        
        for(const vector<int>&point:points){
            pq.push(point);
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<vector<int>>result;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
    }
};