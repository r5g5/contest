class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int noOfRows = heightMap.size();
        int noOfCols = heightMap[0].size();

        vector<vector<bool>> visited(noOfRows, vector<bool>(noOfCols, false));
        priority_queue<Cell> pq;

        for (int i = 0; i < noOfRows; i++) {
            int height = heightMap[i][0];
            pq.push(Cell(height, i, 0));
            height = heightMap[i][noOfCols - 1];
            pq.push(Cell(height, i, noOfCols - 1));
            visited[i][0] = true;
            visited[i][noOfCols-1] = true;
        }

        for (int i = 0; i < noOfCols; i++) {
            int height = heightMap[0][i];
            pq.push(Cell(height, 0, i));
            height = heightMap[noOfRows - 1][i];
            pq.push(Cell(height,noOfRows-1, i));
            visited[noOfRows-1][i] = true;
            visited[0][i] = true;
        }

        vector<int> dRow = {0, 0, -1, 1};
        vector<int> dCol = {-1, 1, 0, 0};

        int ans = 0;

        while (!pq.empty()) {
            Cell bestCell = pq.top(); pq.pop();
            int minHeight = bestCell.height;
            int currentRow = bestCell.row;
            int currentCol = bestCell.col;
            for (int i = 0; i < 4; i++) {
                int neighbourRow = currentRow + dRow[i];
                int neighbourCol = currentCol + dCol[i];
                if (isValid(neighbourRow, neighbourCol, noOfRows, noOfCols) && !visited[neighbourRow][neighbourCol]) {
                    int thisHeight = heightMap[neighbourRow][neighbourCol];
                    if (thisHeight < minHeight) {
                        ans += minHeight - thisHeight;
                    }

                    pq.push(Cell(max(thisHeight, minHeight), neighbourRow, neighbourCol));
                    visited[neighbourRow][neighbourCol] = true;
                }
            }
        }
        return ans;
    }
private:
    struct Cell
    {
        int height, row, col;
        Cell(int height, int row, int col) : height(height), row(row), col(col) {}
        bool operator<(const Cell& other) const {
            return height >= other.height;
        }
    };
    bool isValid(int row, int col, int maxRow, int maxCol) {
        return (row >= 0 && col >= 0 && row < maxRow && col < maxCol);
    }
};