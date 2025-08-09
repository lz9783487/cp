struct LCA {
    vector<vector<int>> f;
    vector<int> dep;
    const int k = 20;
    void init(int n, vector<vector<int>> g) {
        f = vector<vector<int>>(n + 1, vector<int>(k + 1, 1));
        dep = vector<int>(n + 1, 0);
        function<void(int, int)> dfs = [&](int u, int x) {
            for (int v: g[u]) {
                if (v != x) {
                    f[v][0] = u;
                    for (int i = 1; i <= k; ++i) {
                        f[v][i] = f[f[v][i - 1]][i - 1];
                    }
                    dep[v] = dep[u] + 1;
                    // 必须先算f[v][...]，再做dfs
                    dfs(v, u);
                }
            }
        };
        dfs(1, 0);
    }
    int lca(int u, int v) {
        if (dep[u] > dep[v]) {
            swap(u, v);
        }
        for (int i = k; i >= 0; --i) {
            if (dep[f[v][i]] >= dep[u]) {
                v = f[v][i];
            }
        }
        if (u == v) {
            return u;
        }
        for (int i = k; i >= 0; --i) {
            if (f[u][i] != f[v][i]) {
                u = f[u][i];
                v = f[v][i];
            }
        }
        assert(u != v and f[u][0] == f[v][0]);
        return f[u][0]; // 父节点是LCA
    };
};

