class Solution {
public:
    bool canBeValid(string s, string locked) {
        size_t sz = s.size();
        if (sz & 1)
            return false;
        int openBrackets = 0, unlocked = 0;

        for (int i = 0; i < sz; i++) {
            if (locked[i] == '0')
                unlocked++;
            else if (s[i] == ')') {
                if (openBrackets > 0)
                    openBrackets--;
                else if (unlocked > 0)
                    unlocked--;
                else
                    return false;
            } else
                openBrackets++;
        }

        if (openBrackets) {
            int balance = 0;
            for (int i = sz - 1; i >= 0; i--) {
                if (locked[i] == '0') {
                    unlocked--;
                    balance--;
                } else if (s[i] == '(') {
                    balance++;
                    openBrackets--;
                } else {
                    balance--;
                }

                if (balance > 0)
                    return false;

                if (openBrackets == 0 /*&& unlocked == 0*/)
                    break;
            }
        }
        return !openBrackets;
    }
};