class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long currSum = 0;
        int ways = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            currSum += nums[i];
            long long remainSum = totalSum - currSum;
            if (currSum >= remainSum)
                ways++;
        }
        return ways;
    }
};