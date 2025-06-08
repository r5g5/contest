class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int prefLen = pref.size();
        int ans = 0;

        for (auto& s : words) {
            if (s.substr(0, prefLen) == pref)
                ans++;
        }   

        return ans;
    }
};