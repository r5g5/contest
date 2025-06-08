class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int totalRows = grid.size(), totalCols = grid[0].size();
        int row = 0, col = 0, ans = 0;

        for (int row = 0; row < totalRows; row++) {
            for (int col = 0; col < totalCols; col++) {
                if (grid[row][col] == 1) {
                    // check the row
                    bool isConnected = false;
                    for (int otherRow = 0; otherRow < totalRows; otherRow++) {
                        if (otherRow != row && grid[otherRow][col] == 1) {
                            ans++;
                            isConnected = true;
                            break;
                        }
                    }
                    if (!isConnected) {
                        for (int otherCol = 0; otherCol < totalCols; otherCol++) {
                            if (otherCol != col && grid[row][otherCol] == 1) {
                                ans++;
                                isConnected = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};