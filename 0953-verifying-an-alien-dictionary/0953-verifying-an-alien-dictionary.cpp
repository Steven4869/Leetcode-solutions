class Solution {
public:
    bool isAlienSorted(vector<string>& word, string order) {
        //We'll compare the two worrds with the order 
        unordered_map<char, int>mp;
        //Insert the order elements into map
        for(int i=0;i<order.size();i++)
            mp[order[i]]=i;
        
        for(int i=0;i<word.size()-1;i++){
            string word1 = word[i];
            string word2 = word[i+1];
            
            int a =0, b=0;
            while(a<word1.size()&&b<word2.size()&&word1[a]==word2[b]){
                a++;
                b++;
            }
            if(b==word2.size()&&a<word1.size())
                return false;
            if(a<word1.size()&&b<word2.size()){
                if(mp[word1[a]]>mp[word2[b]])
                    return false;
            }
        }
        return true;
        
    }
};