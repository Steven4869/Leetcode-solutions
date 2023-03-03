// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start =1;
        int end = n;
        int temp;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isBadVersion(mid)==true){
                temp=mid;
                end=mid-1;
            }
            else if(isBadVersion(mid)==false){
                start=mid+1;
            }
        }
        return temp;
    }
};