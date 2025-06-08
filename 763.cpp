class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> charToIdxMap;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (charToIdxMap.contains(s[i])) {
                charToIdxMap[s[i]].second = i;
            } else {
                charToIdxMap[s[i]] = {i, i};
            }
        }

        vector<int> ans;
        int currSize = 0, endPos = 0;

        for (int i = 0; i < s.size(); i++) {
            currSize++;
            endPos = max(endPos, charToIdxMap[s[i]].second);
            if (endPos == i) {
                ans.emplace_back(currSize);
                currSize = 0;
            }
        }

        return ans;
    }
};