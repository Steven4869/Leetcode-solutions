class Solution {
public:
    int partitionString(string s) {
        //The basic solution of this question is to maintain a map 
        //and increment the count if we found the similar element 
        //Then clear the map
        
        unordered_map<char, int> mp;
        int count =1;
        for(int i=0;i<s.size();i++){
            
            if(mp.count(s[i])){
                count++;
                mp.clear();
            }
            mp[s[i]]=i;
        }
        return count;
    }
};