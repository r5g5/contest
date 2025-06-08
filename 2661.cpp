class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m_row = mat.size(), n_col = mat[0].size();
        unordered_map<int, pair<int, int>> valCoordinatesMap;

        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < n_col; j++) {
                int val = mat[i][j];
                valCoordinatesMap[val] = std::make_pair(i, j);
            }
        }

        vector<int> setRows(m_row, 0), setCols(n_col, 0);

        for (int i = 0; i < m_row * n_col; i++) {
            int val = arr[i];
            std::pair<int, int> coordinates = valCoordinatesMap[val];
//            setRows[coordinates.first]++;
//            setCols[coordinates.second]++;
            if ((++setRows[coordinates.first] == n_col) || (++setCols[coordinates.second] == m_row))
                return i;
        }
        return (m_row * n_col) -1 ;
    }
};