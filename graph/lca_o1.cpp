#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
    #include <other/debug.h>
#else
    #define debug(...) 0
#endif
using namespace std;
using pli = pair<int64_t, int>;
unsigned int A, B, C;
inline unsigned int rng61() {
    A ^= A << 16;
    A ^= A >> 5;
    A ^= A << 1;
    unsigned int t = A;
    A = B;
    B = C;
    C ^= t ^ A;
    return C;
}
template <typename A, typename B>
bool ckmn(A &x, const B &y) {
    return x > y && (x = y, true);
}
template <typename A, typename B>
bool ckmx(A &x, const B &y) {
    return x < y && (x = y, true);
}
struct rmq {
    using Compare = less<pli>;
    vector<vector<pair<int64_t, int>>> d;
    rmq(const vector<pli> &a) { // [0, n)
        int n = (int) a.size();
        int log_n = 0;
        while ((1 << log_n) <= n) log_n++;
        d = vector<vector<pli>>(n, vector<pli>(log_n));
        for (int i = 0; i < n; ++i) d[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                d[i][j] = Compare()(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]) ? d[i][j - 1] : d[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    pli query(int l, int r) { // [l, r)
        int k = 0;
        while (1 << (k + 1) <= r - l) k++;
        return Compare()(d[l][k], d[r - (1 << k)][k]) ? d[l][k] : d[r - (1 << k)][k];
    }
};
int main(){
    const int inf = (int) 1e9;
    int n, m;
    scanf("%d%d%u%u%u", &n, &m, &A, &B, &C);
    vector<vector<int>> g(n);
    {
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            --a, --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    vector<int> p(n, inf), dep(n, 0);
    vector<int64_t> s;
    function<void(int, int)> dfs = [&](int u, int father) {
        s.push_back(u);
        ckmn(p[u], int(s.size()) - 1);
        for (auto v : g[u]) {
            if (v == father) {
                continue;
            }
            dep[v] = dep[u] + 1;
            dfs(v, u);
            s.push_back(u);
        }
    };
    dfs(0, 0);
    vector<pli> a(s.size());
    for (int i = 0; i < int(s.size()); ++i) {
        a[i] = {dep[s[i]], s[i]};
    }
    rmq r(a);
    function<int(int, int)> lca = [&](int u, int v) -> int {
        --u, --v;
        int iu = p[u], iv = p[v];
        if (iu > iv) {
            swap(iu, iv);
        }
        return r.query(iu, iv + 1).second;
    };
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        unsigned int u = rng61() % n + 1, v = rng61() % n + 1;
        long long ans_i = lca(u, v) + 1;
        ans ^= ans_i * i;
    }
    printf("%lld\n", ans);
}