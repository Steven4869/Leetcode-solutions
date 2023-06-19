class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>result(gain.size()+1);
        result.push_back(0);
        
        for(int i=0;i<gain.size();i++){
            result[i+1]=gain[i]+result[i];
        }
        int highestAltitude=0;
        for(auto altitude:result){
            highestAltitude = max(altitude, highestAltitude);
        }
        return highestAltitude;
    }
};