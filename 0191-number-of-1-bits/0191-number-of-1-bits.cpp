class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n){
            int bits=(n&1);
            if(bits==1)
                count++;
            n=n>>1;
        }
        return count;
    }
};