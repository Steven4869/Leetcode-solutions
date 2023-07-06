class Solution {
public:
    long long check(vector<int>& piles, int k) {
        long long  sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += (piles[i] + k - 1) / k;
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = 1e9;
        int ans;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(piles, mid) <= h) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};