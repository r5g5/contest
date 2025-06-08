class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int& i : answers) {
            mp[i]++;
        }

        for (auto& kvp : mp) {
            ans += ceil(kvp.second / (kvp.first + 1)) * (kvp.first + 1);
        }

        return ans;
    }
};