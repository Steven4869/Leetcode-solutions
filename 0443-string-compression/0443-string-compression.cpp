class Solution {
public:
    int compress(vector<char>& chars) {
        int result =0;
        int i=0;
        while(i<chars.size()){
            int groupLength=1;
            while(i+groupLength<chars.size()&&chars[i+groupLength]==chars[i]){
                groupLength++;
            }
            chars[result++]=chars[i];
            if(groupLength>1){
                for(char c: to_string(groupLength)){
                    chars[result++]=c;
                }
            }
            i+=groupLength;
        }
        return result;
    }
};