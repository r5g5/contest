class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, bool> safe;
        vector<int> ans;
        int n = graph.size();

        function<bool(int)> dfs = [&](int i) -> bool {
            if (safe.find(i) != safe.end())
                return safe[i];
            safe[i] = false;
            for (auto& j : graph[i]) {
                if (!dfs(j))
                    return false;
            }
            return safe[i] = true;
        };
        for (int i = 0; i < n; i++) {
            if (dfs(i)) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};