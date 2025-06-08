class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<int> adjList[n];

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        int cycleStart = -1;

        function<void(int)> dfs = [&] (int source) -> void {
            visited[source] = true;
            for (auto& u : adjList[source]) {
                if (!visited[u]) {
                    parent[u] = source;
                    dfs(u);
                } else if (parent[source] != u && cycleStart == -1) {
                    cycleStart = u;
                    parent[u] = source;
                }
            }
        };

        dfs(1);

        unordered_map<int, bool> cycleNodes;
        int node = cycleStart;

        do {
            cycleNodes[node] = true;
            node = parent[node];
        } while (node != cycleStart);

        std::reverse(edges.begin(), edges.end());
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (cycleNodes[u] && cycleNodes[v])
                return edge;
        }
        return {};
    }
};