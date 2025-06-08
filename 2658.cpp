class Solution {
private:
    inline bool isValid(int row, int col, int maxRow, int maxCol) {
        return (row >= 0 && col >= 0 && row < maxRow && col < maxCol);
    }
    vector<int> dRow = {0, 0, -1, 1};
    vector<int> dCol = {-1, 1, 0, 0};
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int mxRow, int mxCol) {
        if (!isValid(r, c, mxRow, mxCol))
            return 0;
        int neighbourSum = grid[r][c];
        visited[r][c] = true;
        if (grid[r][c]) {
            for (int i = 0; i < 4; i++) {
                int currRow = r + dRow[i], currCol = c + dCol[i];
                if (isValid(currRow, currCol, mxRow, mxCol) && !visited[currRow][currCol]) {
                    visited[currRow][currCol] = true;
                    neighbourSum += dfs(grid, visited, currRow, currCol, mxRow, mxCol);
                }
            }
        }
        return neighbourSum;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    vector<vector<bool>> visited(m, vector<bool> (n, false));
                    ans = max(ans, dfs(grid, visited, i, j, m, n));
                }
            }
        }
        return ans;
    }
};