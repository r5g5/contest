class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        size_t sz = A.size();
        vector<int> ans(sz, 0), freq(sz + 1, 0);
        for (int i = 0, cnt = 0; i < sz; i++) {
            if (++freq[A[i]] == 2) ++cnt;
            if (++freq[B[i]] == 2) ++cnt;
            ans[i] = cnt;
        }
        return ans;
    }
};