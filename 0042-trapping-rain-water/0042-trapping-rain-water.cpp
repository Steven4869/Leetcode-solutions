class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2)
            return 0;
        
        int left=0, right = n-1;
        int leftMax=0, rightMax=0;
        int trappedWater;
        
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>leftMax){
                    leftMax = height[left];
                }
                else{
                    trappedWater = trappedWater + leftMax - height[left];
                }
                left++;
            }
            else{
                if(height[right]>rightMax){
                    rightMax = height[right];
                }
                else{
                    trappedWater = trappedWater + rightMax - height[right];
                }
                right--;
            }
        }
        return trappedWater;
    }
};