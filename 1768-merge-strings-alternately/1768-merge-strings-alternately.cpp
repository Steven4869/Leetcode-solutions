class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word = "";
        int m=word1.size(), n=word2.size();
        int i=0, j=0;
        while(i<m||j<n){
            if(i<m){
                word.push_back(word1[i]);
                i++;
            }
            if(j<n){
                word.push_back(word2[j]);
                j++;
            }
        }
        return word;
    }
};