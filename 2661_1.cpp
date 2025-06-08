class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m_row = mat.size(), n_col = mat[0].size();
        vector<int> numToIdxMap(m_row * n_col + 1, 0);
        for (int i = 0; i < m_row * n_col; i++)
            numToIdxMap[arr[i]] = i;

        int ans = INT_MAX;
        for (int row = 0; row < m_row; row++) {
            int rowOptCount = INT_MIN;
            for (int col = 0; col < n_col; col++) {
                rowOptCount = max(rowOptCount, numToIdxMap[mat[row][col]]);
            }
            ans = min(ans, rowOptCount);
        }

        for (int col = 0; col < n_col; col++) {
            int colOptCount = INT_MIN;
            for (int row = 0; row < m_row; row++) {
                colOptCount = max(colOptCount, numToIdxMap[mat[row][col]]);
            }
            ans = min(ans, colOptCount);
        }

        return ans;
    }
};