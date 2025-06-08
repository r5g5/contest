class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        size_t sz = s.size();
        vector<int> diff(sz + 1, 0);

        for (vector<int>& queries : shifts) {
            int l = queries[0];
            int r = queries[1];
            int dir = queries[2] == 0 ? -1 : 1;

            diff[l] += dir;
            diff[r + 1] += -dir;
        }

        for (int i = 1; i < sz; i++) {
            diff[i] += diff[i-1];
        }

        for (int i = 0; i < sz; i++) {
            int newValue = (s[i] -'a' + diff[i]) % 26;
            if (newValue < 0)
                newValue += 26;
            s[i] = 'a' + (newValue%26);
        }
        return s;
    }
};