class Solution {
public:
    string clearDigits(string s) {
        bool contains_digit = false;
        do {
            contains_digit = false;
            for (int i = 1; i < s.size(); i++) {
                if (isdigit(s[i]) && !isdigit(s[i-1])) {
                    std::string first = s.substr(0, i - 1), second; /* s.substr(i + 1, s.size())*/;
                    if (i +1  < s.size()) {
                        second = s.substr(i + 1, s.size());
                    }
                    s = first + second;
                    contains_digit = true;
                    break;
                }
            }
        } while (contains_digit);
        return s;
    }
};