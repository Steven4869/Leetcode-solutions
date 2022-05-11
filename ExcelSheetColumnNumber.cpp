// Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...
 

// Example 1:

// Input: columnTitle = "A"
// Output: 1

class Solution {
public:
    int titleToNumber(string columnTitle) {
        //The reason we are using res *26 + ColumnTitle[i] - 'A' +1
        //Since no value from starts from 1 we are taking the columtitle's avleu subtratcing eith A and adding 1 to it 
        //ZY=> result = 0*26+ Z-A + 1 => 26
        // i =1; result = 26*26 + Y-A+1=> 676+25=701
        long result =0;
        for(int i=0;i<columnTitle.size();i++){
            result = result*26 + columnTitle[i]-'A'+1;
        }
        return result;
    }
};
