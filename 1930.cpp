class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; char c : s) {
            int index = c - 'a';
            if (first[index] == -1) {
                first[index] = i;
            }
            last[index] = i++;
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            int f = first[i];
            if (f != -1) {
                int l = last[i];
                unordered_set<char> ss;
                for (int k = f + 1; k < l; k++) {
                    ss.insert(s[k]);
                }
                ans += ss.size();
            }
        }
        return ans;
    }
};