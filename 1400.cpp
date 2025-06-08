class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        int track = 0;
        for (char c : s) {
            track ^= 1 << (c - 'a');
        }
        int setBits = __builtin_popcount(track);
        return setBits <= k;
    }
};