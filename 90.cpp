class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sub;
    set<vector<int>> used;

    void search(vector<int>& nums, int i) {
        if (i == nums.size()) {
            if (find(used.begin(), used.end(), sub) == used.end()) {
                used.insert(sub);
                ans.push_back(sub);
            }
        } else {
            sub.emplace_back(nums[i]);
            search(nums, i + 1);
            sub.pop_back();
            search(nums, i + 1);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        search(nums, 0);
        return ans;
    }
};