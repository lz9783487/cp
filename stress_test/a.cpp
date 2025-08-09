#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <other/debug.h>
#else
    #define debug(...) 0
#endif
    #define debug(...) 0
using namespace std;
// https://atcoder.github.io/ac-library/production/document_en/lazysegtree.html
#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1
#ifdef _MSC_VER
		#include <intrin.h>
#endif
#if __cplusplus >= 202002L
		#include <bit>
#endif
namespace atcoder {
namespace internal {
#if __cplusplus >= 202002L

				using std::bit_ceil;

#else
// @return same with std::bit::bit_ceil
unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < (unsigned int) (n)) x *= 2;
    return x;
}
#endif
// @param n `1 <= n`
// @return same with std::bit::countr_zero
int countr_zero(unsigned int n) {
#ifdef _MSC_VER
					unsigned long index;
					_BitScanForward(&index, n);
					return index;
#else
    return __builtin_ctz(n);
#endif
}
} // namespace internal
} // namespace atcoder
#endif  // ATCODER_INTERNAL_BITOP_HPP
#ifndef ATCODER_LAZYSEGTREE_HPP
#define ATCODER_LAZYSEGTREE_HPP 1
#include <cassert>
#include <functional>
#include <vector>

namespace atcoder {
template<class S,
    S (* op)(S, S),
    S (* e)(),
    class F,
    S (* mapping)(F, S),
    F (* composition)(F, F),
    F (* id)()>
struct lazy_segtree {
    lazy_segtree() : lazy_segtree(0) {
    }
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {
    }
    explicit lazy_segtree(const std::vector<S> &v) : _n(int(v.size())) {
        size = (int) internal::bit_ceil((unsigned int) (_n));
        log = internal::countr_zero((unsigned int) size);
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }
    S prod(int l, int r) {
        debug("prod", l, r);
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
    S all_prod() { return d[1]; }
    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        debug("apply", l, r);
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        } {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};
} // namespace atcoder
#endif  // ATCODER_LAZYSEGTREE_HPP
struct S {
    int cl, cr, n_seg;
    S() : cl(0), cr(0), n_seg(0) {
    }
    S(int cl, int cr, int n_seg) : cl(cl), cr(cr), n_seg(n_seg) {
    }
};
S e() {
    return S{-1, -1, 0};
}
string toString(S s) {
    return "S = {"
           + to_string(s.cl) + ", "
           + to_string(s.cr) + ", "
           + to_string(s.n_seg) + "}";
}
S op(S a, S b) {
    if (a.n_seg == 0) return b;
    if (b.n_seg == 0) return a;
    if (a.cr == b.cl) {
        return S(a.cl, b.cr, a.n_seg + b.n_seg - 1);
    }
    return S(a.cl, b.cr, a.n_seg + b.n_seg);
}
struct F {
    int64_t color;
    F(int64_t color = -1) : color(color) {
    }
};
S mapping(F f, S s) {
    if (f.color == -1) return s;
    s.cl = s.cr = f.color;
    s.n_seg = 1;
    return s;
}
F composition(F f, F _) {
    if (f.color == -1)
        return _;
    return f;
}
F id() {
    return F(-1);
}
using Tree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

namespace Dfs {
vector<vector<int> > g;
vector<int> dep, fa, top, hson, siz, dft, the;
int dfs_time;
void init(const int n) {
    assert(n > 0);
    g = vector<vector<int> >(n);
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
    for (auto v: g[x]) {
        if (v != f) {
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
    for (const auto v: g[x]) {
        if (v != fa[x] && v != hson[x]) {
            dfs2(v, v);
        }
    }
}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    Dfs::init(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        Dfs::add_edge(a, b);
    }
    Dfs::dfs1(0, 0), Dfs::dfs2(0, 0);
    vector<S> z(n);
    for (int i = 0; i < n; ++i) {
        z[Dfs::dft[i]] = S(c[i], c[i], 1);
    }
    debug(Dfs::dft);
    Tree tree(z);
    function<void(int, int, int)> update = [&](int u, int v, int color) {
        using namespace Dfs;
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) {
                swap(u, v);
            }
            tree.apply(dft[top[u]], dft[u] + 1, F(color));
            u = fa[top[u]];
        }
        if (dep[u] < dep[v]) {
            swap(u, v);
        }
        tree.apply(dft[v], dft[u] + 1, F(color));
    };
    function<int(int, int)> query = [&](int u, int v) {
        using namespace Dfs;
        S resu = e(), resv = e();
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                resu = op(tree.prod(dft[top[u]], dft[u] + 1), resu);
                u = fa[top[u]];
            } else {
                resv = op(tree.prod(dft[top[v]], dft[v] + 1), resv);
                v = fa[top[v]];
            }
        }
        if (dep[u] > dep[v]) {
            resu = op(tree.prod(dft[v], dft[u] + 1), resu);
        } else {
            resv = op(tree.prod(dft[u], dft[v] + 1), resv);
        }
        debug(resu, resv);
        swap(resu.cl, resu.cr);
        return op(resu, resv).n_seg;
    };
    while (m--) {
        char ch;
        cin >> ch;
        if (ch == 'C') {
            int a, b, color;
            cin >> a >> b >> color;
            --a, --b;
            update(a, b, color);
        } else {
            int a, b;
            cin >> a >> b;
            --a, --b;
            cout << query(a, b) << '\n';
        }
    }
    return 0;
}
