class Solution {
private:
    bool isConnected(int source, int target, vector<bool>& visited, vector<int> adjList[]) {
        visited[source] = target;
        if (source == target)
            return true;
        bool isFound = false;
        for (int& u : adjList[source]) {
            if (visited[u]) continue;
            isFound |= isConnected(u, target, visited, adjList);
        }
        return isFound;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> adj[n+1];

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            vector<bool> visited(n+1, false);
            if (isConnected(u, v, visited, adj)) {
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};