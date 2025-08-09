namespace zhu { // 主席树模板
#define mid ((l + r) >> 1)
#define lc (o << 1)
#define rc (o << 1 | 1)
    typedef long long LL;
    const int LOG = 20;
    int n, m, q, tot = 0;
    int a[N], b[N];
    int T[N], sum[N * LOG], L[N * LOG], R[N * LOG];

    inline int build(int l, int r) {
        int rt = ++tot;
        if (l < r) L[rt] = build(l, mid), R[rt] = build(mid + 1, r);
        return rt;
    }

    inline int update(int pre, int l, int r, int x) {
        int rt = ++tot;
        L[rt] = L[pre];
        R[rt] = R[pre];
        sum[rt] = sum[pre] + 1;
        if (l != r) {
            if (x <= mid) L[rt] = update(L[pre], l, mid, x);
            else R[rt] = update(R[pre], mid + 1, r, x);
        }
        return rt;
    }

    inline int query(int u, int v, int l, int r, int k) {
        if (l == r) return l;
        int x = sum[L[v]] - sum[L[u]];
        if (x >= k) return query(L[u], L[v], l, mid, k);
        else return query(R[u], R[v], mid + 1, r, k - x);
    }

    void init(int *_a, int _n) {
        tot = 0;
        n = _n;
        memset(T, 0, sizeof T);
        memset(L, 0, sizeof L);
        memset(R, 0, sizeof R);
        memset(sum, 0, sizeof sum);
        for (int i = 1; i <= n; i++) a[i] = _a[i], b[i] = a[i];
        std::sort(b + 1, b + 1 + n);
        m = std::unique(b + 1, b + 1 + n) - b - 1;
        T[0] = build(1, m);
        for (int i = 1; i <= n; i++) {
            a[i] = std::lower_bound(b + 1, b + 1 + m, a[i]) - b, T[i] = update(T[i - 1], 1, m, a[i]);
        }
    }

    int query(int x, int y, int z) {
        int p = query(T[x - 1], T[y], 1, m, z);
        return b[p];
    }
}
