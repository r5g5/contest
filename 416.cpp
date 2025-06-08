class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum & 1)
            return false;
        int target = totalSum / 2;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> tmpSet;
            tmpSet.insert(nums[i]);
            for (auto& j : s) {
                tmpSet.insert(j + nums[i]);
            }
            s.insert(tmpSet.begin(), tmpSet.end());
        }

        for (auto& element : s) {
            if (element == target)
                return true;
        }
        return false;
    }
};