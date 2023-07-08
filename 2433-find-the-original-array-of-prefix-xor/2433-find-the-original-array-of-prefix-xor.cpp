class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int ans = pref[0];
        vector<int>result(pref.size());
        result[0] = pref[0];
        for(int i=1;i<pref.size();i++){
            result[i]=pref[i]^ans;
            ans = pref[i];
        }
        return result;
    }
};