class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>mp;
        for(char num:s){
            mp[num]++;
        }
        
        //Creating comprator function based on frequency
        
        auto comp = [](const pair<char,int>&p1, const pair<char,int>&p2){
            if(p1.second == p2.second){
                //Then arrange it n lexiographic order 
                return p1.first>p2.first;
            }
            return p1.second<p2.second;
        };
        
        //Creating a Max Heap with comprator 
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(comp)>pq(comp);
        
        for(auto entry:mp){
            pq.push(entry);
        }
        
        string result = "";
        
        while(!pq.empty()){
            auto element = pq.top();
            pq.pop();
            
            result = result + string(element.second, element.first);
        }
        
        return result;
        
    }
};