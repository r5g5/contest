class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int best = 1, strInc = 1, strDec = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                strInc++;
                strDec = 1;
            } else if (nums[i] < nums[i-1]) {
                strDec++;
                strInc = 1;
            } else {
                strDec = strInc = 1;
            }
            best = max(best, max(strInc, strDec));
        }
        return best;
    }
};