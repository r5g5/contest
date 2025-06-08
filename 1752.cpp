class Solution {
public:
    bool check(vector<int>& nums) {
        const int n = nums.size();
        int inv = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] < nums[i-1])
                inv++;
        }
        if (nums[0] < nums[n-1])
            inv++;
        return inv <= 1;
    }
};