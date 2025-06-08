class Solution {
private:
    bool doesPathExists(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int source, int target) {
        visited[source] = true;
        if (source == target)
            return true;
        bool ok = false;
        for (auto& u : adj[source]) {
            if (!visited[u]) {
                ok |= doesPathExists(adj, visited, u, target);
            }
        }
        return ok;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }      
        vector<bool> ans;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            vector<bool> visited(numCourses, false);
            ans.emplace_back(doesPathExists(adj, visited, u, v));
        }
        return ans;
    }
};