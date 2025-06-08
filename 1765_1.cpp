class Solution {
private:
    inline bool isValid(int r, int c, int mr, int mc) {
        return (r >= 0 && c >= 0 && r < mr && c < mc);
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size(), cols = isWater[0].size();
        int INF = rows * cols;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (isWater[row][col]) {
                    isWater[row][col] = 0;
                    continue;
                }
                isWater[row][col] = INF;
            }
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // check the up value and the left
                int upd = INF;
                if (isValid(row - 1, col, rows, cols)) {
                    upd = min(upd, isWater[row-1][col]);
                }
                if (isValid(row, col - 1, rows, cols)) {
                    upd = min(upd, isWater[row][col-1]);
                }

                isWater[row][col] = min(isWater[row][col], upd + 1);
            }
        }

        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                // check the down and the right
                int upd = INF;
                if (isValid(row, col + 1, rows, cols)) {
                    upd = min(upd, isWater[row][col + 1]);
                }

                if (isValid(row + 1, col, rows, cols)) {
                    upd = min(upd, isWater[row+1][col]);
                }

                isWater[row][col] = min(isWater[row][col], upd + 1);
            }
        }
        return isWater;
    }
};