class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> permutation;
        vector<bool> chosen(n, false);

        function<void()> search = [&] () -> void {
            if (permutation.size() == n) {
                ans.push_back(permutation);
            } else {
                for (int i = 0; i < n; i++) {
                    if (chosen[i]) continue;
                    chosen[i] = true;
                    permutation.push_back(nums[i]);
                    search();
                    permutation.pop_back();
                    chosen[i] = false;
                }
            }
        };
        search();
        return ans;
    }
};