class Solution {
public:
    int setBits(int n){
        int count=0;
        while(n){
            int bits = n&1;
            if(bits==1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
    int hammingDistance(int x, int y) {
        return setBits(x^y);
    }
};