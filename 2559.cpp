class Solution {
public:
    inline bool isValid(string& word) {
        size_t isz = word.size() - 1;
        return ((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') && (word[isz] == 'a' || word[isz] == 'e' || word[isz] == 'i' || word[isz] == 'o' || word[isz] == 'u'));
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixSum(words.size() + 1, 0);
        for (int i = 0, vowelsCnt = 0;i < words.size(); i++) {
            if (isValid(words[i])) {
                vowelsCnt++;
            }
            prefixSum[i+1] = vowelsCnt;
        }

        vector<int> ans(queries.size(), 0);
        for (int i = 0; auto& p : queries) {
            int l = p[0];
            int r = p[1] + 1;
            ans[i++] = prefixSum[r] - prefixSum[l];
        }
        return ans;
    }
};