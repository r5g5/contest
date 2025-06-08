class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> reversedGraph(n);

        for (int i = 0; auto person : favorite) {
            reversedGraph[person].push_back(i++);
        }

        auto bfs = [&](unordered_set<int>& visitedNodes, int source)->int {
            int maxDistance = 0;
            queue<pair<int, int>> q;
            q.push({source, 0});
            while (!q.empty()) {
                auto [node, distance] = q.front(); q.pop();
                for (auto& neighbours : reversedGraph[node]) {
                    if (visitedNodes.count(neighbours)) continue;
                    maxDistance = max(maxDistance, distance + 1);
                    q.push({neighbours, distance + 1});
                }
            }
            return maxDistance;
        };

        vector<bool> visited(n, false);
        int twoPairInit = 0, longestCycle = 0;

        for (int person = 0; person < n; person++) {
            if (!visited[person]) {
                int current = person, distance = 0;
                unordered_map<int, int> visitedPerson;
                while (true) {
                    if (visited[current]) break;
                    visited[current] = true;
                    visitedPerson[current] = distance++;
                    int nextPerson = favorite[current];
                    if (visitedPerson.count(nextPerson)) {
                        int cycleLen = distance - visitedPerson[nextPerson];
                        longestCycle = max(cycleLen, longestCycle);
                        if (cycleLen == 2) {
                            unordered_set<int> visitedNodes = {current, nextPerson};
                            twoPairInit += (2 + bfs(visitedNodes, current) + bfs(visitedNodes, nextPerson));
                        }
                    }
                    current = favorite[current];
                }
            }
        }
        return max(longestCycle, twoPairInit);
    }
};