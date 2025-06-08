class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0, best = 0, n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i+1]) {
                sum += nums[i];
            } else {
                sum += nums[i];
                best = max(best, sum);
                sum = 0;
            }
        }

        if (nums[n - 1] > nums[n-2])
            sum += nums[n - 1];
        return max(best, sum);
    }
};