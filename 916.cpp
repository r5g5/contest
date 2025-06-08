class Solution {
    unordered_map<char, int> mp2;
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        size_t sz1 = words1.size(); //, sz2 = words2.size();
        vector<unordered_map<char, int>> mp1(sz1);
        for (auto& word : words2) {
            solve(word); // m^2
        }
        vector<string> ans;
        for (int i = 0; i < sz1; i++) { // n
            for (char c : words1[i]) {
                mp1[i][c]++;
            } // frequency ( n)
            bool ok = true;
            for (auto& item : mp2) {
                if (item.second > mp1[i][item.first])
                {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
    void solve(string& s) {
        unordered_map<char, bool> used;
        for (auto& u : s) {
            if (used.find(u) == used.end()) {
                used[u] = true;
                int cnt = count(s.begin(), s.end(), u);
                mp2[u] = max(cnt, mp2[u]);
            }
        }
        return;
    }
};