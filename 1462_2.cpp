class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for (auto& edge : prerequisites) {
            int u = edge[0], v = edge[1];
            adjList[u].emplace_back(v);
        }

        vector<vector<bool>> isPreRequisite(numCourses, vector<bool>(numCourses, false));

        auto bfs = [&](unordered_map<int, vector<int>>& adjList, vector<vector<bool>>& Pre, int u) {
            queue<int> q;
            q.push(u);
            int top = u;
            while (!q.empty()) {
                u = q.front(); q.pop();
                for (auto &v : adjList[u]) {
                    if (!Pre[top][v]) {
                        Pre[top][v] = true;
                        q.push(v);
                    }
                }
            }
        };

        for (int i = 0; i < numCourses; i++) {
            bfs(adjList, isPreRequisite, i);
        }
        vector<bool> answer;
        for (auto& query : queries) {
            answer.push_back(isPreRequisite[query[0]][query[1]]);
        }
        return answer;
    }
};