class Solution {
private:
    inline bool isValid(int r, int c, int mr, int mc) {
        return (r >= 0 && c >= 0 && r < mr && c < mc);
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        const int INF = rows + cols;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (mat[row][col]) {
                    mat[row][col] = INF;
                }
            }
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int upd = INF;
                // check the top and the left value.
                if (isValid(row-1, col, rows, cols)) {
                    upd = min(upd, mat[row-1][col]);
                }
                if (isValid(row, col-1, rows, cols)) {
                    upd = min(upd, mat[row][col-1]);
                }
                mat[row][col] = min(mat[row][col], upd + 1);
            }
        }

        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                int upd = INF;
                // check the bottom and the right value.
                if (isValid(row+1, col, rows, cols)) {
                    upd = min(upd, mat[row+1][col]);
                }
                if (isValid(row, col+1, rows, cols)) {
                    upd = min(upd, mat[row][col+1]);
                }
                mat[row][col] = min(mat[row][col], upd + 1);
            }
        }

        return mat;
    }
};