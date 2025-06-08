class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<Cell> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j]) {
                        isWater[i][j] = 0;
                    q.push(Cell(isWater[i][j], i, j));
                    visited[i][j] = true;
                }
            }
        }
        vector<int> dRow = {0, 0, -1, 1};
        vector<int> dCol = {-1, 1, 0, 0};

        while (!q.empty()) {
            Cell cell = q.front(); q.pop();
            int val = cell.value;
            int x = cell.x, y = cell.y;
            // Go to its neighbours.
            for (int i = 0; i < 4; i++) {
                if (isValid(x + dRow[i], y + dCol[i], n, m) && !visited[x + dRow[i]][y + dCol[i]]) {
                    visited[x + dRow[i]][y + dCol[i]] = true;
                    isWater[x + dRow[i]][y + dCol[i]] = val + 1;
                    q.push(Cell(isWater[x + dRow[i]][y + dCol[i]], x + dRow[i], y + dCol[i]));
                }
            }
        }

        return isWater;
    }
private:
    inline bool isValid(int row, int col, int maxRow, int maxCol) {
        return (row >= 0 && col >= 0 && row < maxRow && col < maxCol);
    }
    struct Cell
    {
        int value, x, y;
        Cell(int value, int x, int y) : value(value), x(x), y(y) {}
    };
};