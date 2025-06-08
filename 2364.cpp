class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badPairs = 0;
        unordered_map<int, int> diffCount;
        for (int pos = 0; pos < nums.size(); pos++) {
            int diff = nums[pos] - pos;
            int goodPairs = diffCount[diff];

            badPairs += pos - goodPairs;

            diffCount[diff]++;
        }

        return badPairs;
    }
};