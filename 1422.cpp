class Solution {
public:
    int maxScore(string s) {
        /*
         * ans = Zl + Or
         * Or = Ot - Ol
         * ans = Zl + Ot -Ol
         */
        int ones = 0, zeros = 0, best = INT_MIN;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0')
                zeros++;
            else
                ones++;

            best = max(best, zeros - ones);
        }
        if (s[s.size() - 1] == '1')
            ones++;
        return best + ones;
    }
};