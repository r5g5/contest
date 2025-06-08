class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int ai = 0, aj = 0, curr = 0;

        for (int diff : differences) {
            curr += diff;
            ai = min(ai, curr);
            aj = max(aj, curr);

            if (aj - ai > upper - lower)
                return 0;
        }

        return (upper - lower) - (aj - ai) + 1;
    }
};