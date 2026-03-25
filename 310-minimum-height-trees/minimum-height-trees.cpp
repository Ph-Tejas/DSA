class Solution {
public:
    int mini = 100000;
    vector<int> freq;
    int n;
    vector<vector<int>> adj;
    // pr[node] stores {{max_height_in_subtree, child_giving_it}, second_max_height}
    vector<pair<pair<int, int>, int>> pr;

    void dfs(int node, int par) {
        int a = 0, b = 0, c = -1;
        for (int child : adj[node]) {
            if (child == par) continue;
            dfs(child, node);
            int h = pr[child].first.first + 1;
            if (h > a) {
                b = a;
                a = h;
                c = child;
            } else if (h > b) {
                b = h;
            }
        }
        pr[node] = {{a, c}, b};
    }

    // upDist is the longest path starting from node going UP to its parent
    void dfs2(int node, int par, int upDist) {
        // The actual height of the tree if 'node' is the root
        int actualMax = max(pr[node].first.first, upDist);

        if (actualMax < mini) {
            mini = actualMax;
            freq = {node};
        } else if (actualMax == mini) {
            freq.push_back(node);
        }

        for (int child : adj[node]) {
            if (child == par) continue;

            // If this child is the one that gave 'node' its max subtree height,
            // the path going "up" for this child must use the second-best option.
            int bestPathFromParent;
            if (child == pr[node].first.second) {
                bestPathFromParent = max(upDist, pr[node].second);
            } else {
                bestPathFromParent = max(upDist, pr[node].first.first);
            }

            dfs2(child, node, bestPathFromParent + 1);
        }
    }

    vector<int> findMinHeightTrees(int n_, vector<vector<int>>& edges) {
        if (n_ == 1) return {0};
        n = n_;
        adj.assign(n, {});
        pr.resize(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        dfs2(0, -1, 0);
        return freq;
    }
};