vector<vector<int>> e;
vector<int> big_son, l, r;
int n;
int64_t ans;
void dfs(int u, int f, bool keep) {
    for (auto v : e[u]) {
        if (v != f && v != big_son[u]) {
            dfs(v, u, 0); // 每个轻儿子回答询问，不保留贡献
        }
    }
    if (big_son[u] != -1) {
        dfs(big_son[u], u, 1); // 保留重儿子的贡献
    }
    for (auto v : e[u]) {
        if (v != f && v != big_son[u]) {
            for (int i = l[v]; i <= r[v]; i++) { // 每个轻儿子的贡献（通过dfs序），其实是启发式合并的过程
                // add dfs_time_id[i]
            }
        }
    }
    // add u !!!
    // ...
    if (!keep) {
        for (int i = l[u]; i <= r[u]; i++) {
            // delete dfs_time_id[i]
        }
    }
}


// example
function<void(int, int, bool)> dfs = [&](const int u, const int f, const bool keep) {
    for (auto v : d.g[u]) {
        if (v != f && v != d.bson[u]) {
            dfs(v, u, false);
        }
    }
    if (d.bson[u] != -1) {
        dfs(d.bson[u], u, true);
    }
    for (auto v : d.g[u]) {
        if (v != f && v != d.bson[u]) {
            for (int time = d.dft[v]; time < d.dft[v] + d.siz[v]; time++) { // 每个轻儿子的贡献（通过dfs序），等价于启发式合并的过程
                add_color(c[d.the[time]]);
            }
        }
    }
    add_color(c[u]); // !!!
    ans[u] = cnt_sum[max_cnt];
    if (!keep) {
        for (int time = d.dft[u]; time < d.dft[u] + d.siz[u]; time++) {
            del_color(c[d.the[time]]);
        }
    }
};
dfs(0, 0, true);