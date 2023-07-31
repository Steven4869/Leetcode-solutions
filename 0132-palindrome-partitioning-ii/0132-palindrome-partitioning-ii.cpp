class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    int minCutRecursive(string& s, int start, vector<int>& dp) {
        if (start == s.length()) {
            return -1; // Base case: no more cuts needed
        }

        if (dp[start] != -1) {
            return dp[start];
        }

        int minCuts = INT_MAX;

        for (int len = 1; start + len <= s.length(); len++) {
            if (isPalindrome(s, start, start + len - 1)) {
                int cuts = minCutRecursive(s, start + len, dp);
                minCuts = min(minCuts, cuts + 1);
            }
        }

        dp[start] = minCuts;
        return minCuts;
    }

    int minCut(string s) {
        vector<int> dp(s.length(), -1);
        return minCutRecursive(s, 0, dp);
    }
};