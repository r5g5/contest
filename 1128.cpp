class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        vector<int> v(100, 0);

        for (auto& it : dominoes) {
            int val = it[0] > it[1] ? it[0] * 10 + it[1] : it[1] * 10 + it[0];
            ans += v[val]++;
        }

        return ans;
    }
};