class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Approach is quite simple 
        // We will keep an set of charcters for storing the unique charcters in the window 
        //Run the loop until we reach the end of the length of string
        //Get the character from the string 
        //Check if the word is in the window or not 
        //If not insert it in the window, update the answer and increment the right 
        // If exists in the window and it is repated then erase from the window and increment the left 
        
        unordered_set<char>window;
        int right = 0;
        int left = 0;
        int n = s.length();
        int result = 0;
        while(right<n){
            char c = s[right];
            if(window.find(c)==window.end()){
                window.insert(c);
                result = max(result, right-left+1);
                right++;
            }
            else{
                window.erase(s[left]);
                left++;
            }
        }
        return result;
    }
};