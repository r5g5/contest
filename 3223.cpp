class Solution {
public:
    int minimumLength(string s) {
        if (s.size() < 3)
            return s.size();
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        int remove = 0;
        for (auto& item : mp) {
            if (item.second <= 2) {
                continue;
            } else if (item.second & 1) {
                remove += item.second - 1;
            } else {
                remove += item.second - 2;
            }
        }
        return s.size() - remove;
    }
};