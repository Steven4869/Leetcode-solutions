class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        char temp;
        
        while(columnNumber){
            columnNumber = columnNumber - 1;
            temp = 'A' + columnNumber%26;
            result = result + temp;
            columnNumber = columnNumber/26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};