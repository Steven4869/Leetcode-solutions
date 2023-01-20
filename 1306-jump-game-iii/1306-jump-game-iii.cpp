class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        //Base condition 
        if(arr[start]==0)
            return true;
        int rightIndex = start + arr[start];
        int leftIndex = start - arr[start];
        
        //Mark it as visited 
        arr[start]=-1;
        
        //Jump to right side if it's less than size of the array
        if(rightIndex < arr.size()&&arr[rightIndex]!=-1&&canReach(arr, rightIndex))
            return true;
        //Jump to left side if it's greater than 0
        if(leftIndex >=0 && arr[leftIndex]!=-1 && canReach(arr, leftIndex))
            return true;
        return false;
    }
};