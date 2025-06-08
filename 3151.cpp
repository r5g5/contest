class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool ok = true;
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] & 1) ^ (nums[i - 1] & 1) == 0) {
                ok = false;
                break;
            }
        }
        return ok;
    }
};