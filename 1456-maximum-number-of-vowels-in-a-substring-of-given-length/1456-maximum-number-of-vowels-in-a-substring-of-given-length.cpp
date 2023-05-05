class Solution {
public:
    int maxVowels(string s, int k) {
        //It's a sliding window question of window lenght of k
        //Just make two pointers left and right, traverse the string with right pointer 
        //and increment the count if you found the vowel
        unordered_set<char>vowels{'a','e','i','o','u'};
        int left=0;
        int count=0;
        int result=0;
        for(int right =0;right<s.length();right++){
            
            if(vowels.find(s[right])!=vowels.end()){
                count++;
            }
            
            if(right-left+1>k){
                if(vowels.find(s[left])!=vowels.end()){
                    count--;
                }
                left++;
            }
            result = max(result, count);
        }
        return result;
    }
};
