class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int K) {
        for (int i = nums.size() - 1; i >= 0 && K > 0; --i) {
            nums[i] += K;
            K = nums[i] / 10;
            nums[i] %= 10;
        }
        while (K > 0) {
            nums.insert(nums.begin(), K % 10);
            K /= 10;
        }
        return nums;
    }
};