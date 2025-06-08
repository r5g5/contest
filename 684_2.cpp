class Solution {
private:
    struct DSU
    {
    private:
        int N;
        vector<int> representative;
        vector<int> size;
    public:
        DSU(int N) : N(N) {
            representative.assign(N, 0);
            iota(representative.begin(), representative.end(), 0);
            size.assign(N, 1);
        }

        bool Union(int nodeOne, int nodeTwo) {
            nodeOne = find(nodeOne);
            nodeTwo = find(nodeTwo);
            if (nodeOne == nodeTwo)
                return false;
            if (nodeOne < nodeTwo) {
                representative[nodeOne] = nodeTwo;
                size[nodeTwo] += size[nodeOne];
            } else {
                representative[nodeTwo] = nodeOne;
                size[nodeOne] += size[nodeTwo];
            }
            return true;
        }

        int find(int node) {
            if (node == representative[node])
                return node;
            return representative[node] = find(representative[node]);
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        DSU dsu(n);
        for (auto& edge : edges) {
            if (!dsu.Union(edge[0], edge[1]))
                return edge;
        }
        return {};
    }
};