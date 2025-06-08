class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        int count = 0, n = s1.size();
        int fiIdx = -1, seIdx = -1;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (fiIdx == -1) {
                    fiIdx = i;
                } else if (seIdx == -1) {
                    seIdx = i;
                }
                count++;
            }
        }
        if (count == 2)
            swap(s2[fiIdx], s2[seIdx]);
        return s1 == s2;
    }
};