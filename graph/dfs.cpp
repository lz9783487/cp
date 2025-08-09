struct Dfs {
    const int default_root = 0;
    int B;
    vector<vector<int>> fas, g;
    vector<int> dep, fa, top, hson, siz, dft, the;
    int dfs_time;
    explicit Dfs(const int n) {
        assert(n > 0);
        if (n - 1 <= 1) { // (1 << B) >= n - 1, 最多跳n - 1次
            B = 0;
        } else {
            int top_bit = 63 - __builtin_clzll(n - 1);
            int more_bit = __builtin_popcountll(n - 1) > 1;
            B = top_bit + more_bit;
        }
        fas.assign(n, vector<int>(B + 1, default_root));
        g = vector<vector<int>>(n);
        dep = fa = top = hson = siz = dft = the = vector<int>(n);
        dfs_time = 0;
    }  
    void add_edge(const int x, const int y) {
        g[x].push_back(y), g[y].push_back(x);
    }
    void dfs1(const int x, const int f) {
        fa[x] = f;
        siz[x] = 1;
        hson[x] = -1;
        for (auto v : g[x]) {
            if (v != f) {
                fas[x][0] = f;
                for (int i = 1; i <= B; i++) {
                    fas[x][i] = fas[fas[x][i - 1]][i - 1];
                }
                dep[v] = dep[x] + 1;
                dfs1(v, x);
                siz[x] += siz[v];
                if (hson[x] == -1 || siz[v] > siz[hson[x]]) {
                    hson[x] = v;
                }
            }
        }
    }
    void dfs2(const int x, const int top_node) {
        top[x] = top_node;
        the[dfs_time] = x;
        dft[x] = dfs_time++;
        if (hson[x] == -1) {
            return;
        }
        dfs2(hson[x], top_node);
        for (const auto v : g[x]) {
            if (v != fa[x] && v != hson[x]) {
                dfs2(v, v);
            }
        }
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) v = fa[top[v]];
            else u = fa[top[u]];
        }
        if (dep[u] < dep[v]) return u;
        else return v;
    }
};
