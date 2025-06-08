class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(n+1, false);

        auto get_connected_components = [&] (int source) -> vector<int> {
            vector<int> component;
            component.emplace_back(source);
            queue<int> q;
            q.push(source);
            while (!q.empty()) {
                int v = q.front(); q.pop();
                for (auto& u : adjList[v]) {
                    if (find(component.begin(), component.end(), u) == component.end()) {
                        component.emplace_back(u);
                        q.push(u);
                        visited[u] = true;
                    }
                }
            }
            return component;
        };

        auto longest_path = [&] (int source) -> int {
            queue<pair<int, int>> q;
            q.push({source, 1});
            unordered_map<int, int> sourceDistMap;
            sourceDistMap[source] = 1;
            int max_groups = 1;
            while (!q.empty()) {
                auto [vertex, len] = q.front(); q.pop();
                for (auto& u : adjList[vertex]) {
                    if (sourceDistMap.find(u) != sourceDistMap.end()) { // already exists.
                        if (sourceDistMap[u] == len)
                            return -1;
                    } else {
                        sourceDistMap[u] = len + 1;
                        q.push({u, len + 1});
                        max_groups = len + 1;
                    }
                }
            }
            return max_groups;
        };

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i])
                continue;
//            cout << i << " === " << visited[i] << endl;
            visited[i] = true;
            vector<int> connected_components = get_connected_components(i);
//            cout << connected_components.size() << endl;
            int max_cnt = 0;
            for (int source : connected_components) {
                int len = longest_path(source);
                if (len == -1)
                    return -1;
                max_cnt = max(len, max_cnt);
            }
            ans += max_cnt;
        }
        return ans;
    }
};