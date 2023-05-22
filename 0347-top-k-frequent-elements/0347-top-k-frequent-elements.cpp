class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size();
            vector<int>result;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
    for (auto i : mp)
    {
        minH.push({i.second, i.first});
        if (minH.size() > k)
        {
            minH.pop();
        }
    }
    while (minH.size() > 0)
    {
        result.push_back(minH.top().second);
        minH.pop();
    }
        return result;
    }
};