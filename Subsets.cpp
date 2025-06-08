class Solution {
private:
    vector<vector<int>> ans;
    vector<int> subset;
public:
    void search(vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(subset);
        } else {
            subset.push_back(nums[i]);
            search(nums, i + 1);
            subset.pop_back();
            search(nums, i + 1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        search(nums, 0);
        return ans;
    }
};