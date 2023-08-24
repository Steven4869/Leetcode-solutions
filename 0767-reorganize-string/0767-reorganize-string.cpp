class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        auto comp = [](const pair<char, int> &p1, const pair<char, int> &p2) {
            return p1.second < p2.second;
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);

        for (auto entry : mp) {
            pq.push(entry);
        }

        string result = "";
        pair<char, int> prev = {'#', 0}; // Initialize with a dummy character

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            result += top.first;
            top.second--;

            if (prev.second > 0) {
                pq.push(prev);
            }

            prev = top;
        }

        return result.length() == s.length() ? result : "";
    }
};
