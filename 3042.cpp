class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[j].size() < words[i].size())
                    continue;
                int lengthOfStringAtI = words[i].size();
                int lengthOfStringAtJ = words[j].size();
                if ((words[j].substr(0, lengthOfStringAtI) == words[i]) && (words[j].substr(lengthOfStringAtJ - lengthOfStringAtI, lengthOfStringAtJ) == words[i])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};