class Solution {
public:
    bool check(int num, int n, int index, int maxSum)
    {
        long long left = 0;
        if(index >= num - 1)
        {
            left = (num * 1LL * (num - 1)) / 2;
            left += (index + 1 - num);
        }
        else if(index < num - 1)
        {
            left = (num * 1LL * (num - 1)) / 2;
            int temp = num - 1 - index;
            left -= (temp * 1LL * (temp + 1)) / 2;
        }
        long long right = 0;
        int cur = (n - 1 - index);
        if(cur >= num - 1)
        {
            right = (num * 1LL * (num - 1)) / 2;
            right += (cur + 1 - num);
        }
        else if(cur < num - 1)
        {
            right = (num * 1LL * (num - 1)) / 2;
            int temp = num - 1 - cur;
            right -= (temp * 1LL * (temp + 1)) / 2;
        }
        long long ans = left + right + num;
        return (ans <= maxSum);
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum;
        int ans = 0;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(check(mid, n, index, maxSum))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};