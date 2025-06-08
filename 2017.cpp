class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL), secondRowSum = 0;
        long long ans = LLONG_MAX;

        for (int i = 0; i < grid[0].size(); i++) {
            firstRowSum -= grid[0][i];
            ans = min(ans, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][i];
        }

        return ans;
    }
};