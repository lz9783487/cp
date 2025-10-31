#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Inf;
template <>
struct Inf<int> {
    const static int value = 1e9;
};
template <>
struct Inf<int64_t> {
    const static int64_t value = 1e18;
};
template <typename T>
struct zkw {
    static const T inf = Inf<T>::value;
    struct Node {
        T sm, lz, mn, mx;
        Node() {
            sm = lz = 0, mn = inf, mx = -inf;
        }
        Node(T _sm, T _lz, T _mn, T _mx) {
            sm = _sm, lz = _lz, mn = _mn, mx = _mx;
        }
    };
    int m{};
    vector<Node> a;
    // 线段树最后一层的下标范围是[m, 2m - 1]
    // 将x的[0, n - 1]映射到[m + 1, m + n], 其中m + n < 2m - 1
    void init(vector<T> x) {
        const int n = static_cast<int>(x.size()) + 2;
        for (m = 4; m < n; m <<= 1) {
        }
        a.resize(m << 1);
        for (int i = 0; i < static_cast<int>(x.size()); i++) {
            a[m + i + 1] = Node(x[i], 0, x[i], x[i]);
        }
        for (int i = m - 1; i >= 1; i--) {
            T sm = a[i << 1].sm + a[i << 1 | 1].sm;
            T lz = 0;
            T mn = min(a[i << 1].mn, a[i << 1 | 1].mn);
            T mx = max(a[i << 1].mx, a[i << 1 | 1].mx);
            a[i] = Node(sm, lz, mn, mx);
        }
    }
    void update(int l, int r, T delta) {
        // [l, r] += delta
        int len = 1, cntl = 0, cntr = 0;
        // 最后一层的开区间(l, r) += delta
        for (l += m + 1 - 1, r += m + 1 + 1; l ^ r ^ 1; l >>= 1, r >>= 1, len <<= 1) {
            if (l < m) {
                a[l].mn = min(a[l << 1].mn, a[l << 1 | 1].mn) + a[l].lz;
                a[l].mx = max(a[l << 1].mx, a[l << 1 | 1].mx) + a[l].lz;
                a[l].sm += cntl * delta;
                a[r].mn = min(a[r << 1].mn, a[r << 1 | 1].mn) + a[r].lz;
                a[r].mx = max(a[r << 1].mx, a[r << 1 | 1].mx) + a[r].lz;
                a[r].sm += cntr * delta;
            }
            if (~l & 1) {
                a[l ^ 1].sm += len * delta;
                a[l ^ 1].lz += delta;
                a[l ^ 1].mn += delta;
                a[l ^ 1].mx += delta;
                cntl += len;
            }
            if (r & 1) {
                a[r ^ 1].sm += len * delta;
                a[r ^ 1].lz += delta;
                a[r ^ 1].mn += delta;
                a[r ^ 1].mx += delta;
                cntr += len;
            }
        }
        for (; l; l >>= 1, r >>= 1) {
            a[l].mn = min(a[l << 1].mn, a[l << 1 | 1].mn) + a[l].lz;
            a[l].mx = max(a[l << 1].mx, a[l << 1 | 1].mx) + a[l].lz;
            a[l].sm += cntl * delta;
            a[r].mn = min(a[r << 1].mn, a[r << 1 | 1].mn) + a[r].lz;
            a[r].mx = max(a[r << 1].mx, a[r << 1 | 1].mx) + a[r].lz;
            a[r].sm += cntr * delta;
        }
    }
    // [l, r]的和, 最小值, 最大值, 注意, 可能返回inf +- 小范围的数
    tuple<T, T, T> query(int l, int r) {
        T sm = 0, lmn = inf, lmx = -inf, rmn = inf, rmx = -inf;
        int len = 1, cntl = 0, cntr = 0;
        for (l += m + 1 - 1, r += m + 1 + 1; l ^ r ^ 1; l >>= 1, r >>= 1, len <<= 1) {
            sm += a[l].lz * cntl;
            sm += a[r].lz * cntr;
            lmn += a[l].lz;
            lmx += a[l].lz;
            rmn += a[r].lz;
            rmx += a[r].lz;
            if (~l & 1) {
                sm += a[l ^ 1].sm;
                lmn = min(lmn, a[l ^ 1].mn);
                lmx = max(lmx, a[l ^ 1].mx);
                cntl += len;
            }
            if (r & 1) {
                sm += a[r ^ 1].sm;
                rmn = min(rmn, a[r ^ 1].mn);
                rmx = max(rmx, a[r ^ 1].mx);
                cntr += len;
            }
        }
        for (; l; l >>= 1, r >>= 1) {
            sm += a[l].lz * cntl;
            lmn += a[l].lz;
            lmx += a[l].lz;
            sm += a[r].lz * cntr;
            rmn += a[r].lz;
            rmx += a[r].lz;
        }
        // 注意可能返回inf += delta, delta来自普通update操作（非错误）
        return make_tuple(sm, min(lmn, rmn), max(lmx, rmx));
    }
};
static_assert(zkw<int>::inf == 1e9);
static_assert(zkw<long long>::inf == 1e18);
template <typename Tp>
void test() {
    auto rd = random_device();
    mt19937_64 gener(rd());
    uniform_int_distribution<int> dist(0, INT32_MAX);
    auto Rand = [&]() -> int {
        return dist(gener);
    };
    zkw<Tp> tree;
    int n = 10000;
    vector<Tp> x(n + 1, 0);
    vector<Tp> brute(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        x[i] = Rand() % 2000 - 1000;
        brute[i] = x[i];
    }
    tree.init(x);
    for (int i = 0; i < 10000; i++) {
        int op = Rand() % 4; // 生成一个0到3之间的随机数，决定执行何种操作
        int l = Rand() % n + 1;
        int r = Rand() % (n - l + 1) + l;
        if (op == 0) {
            // 区间修改操作
            Tp delta = Rand() % 2000 - 1000;
            tree.update(l, r, delta);
            for (int j = l; j <= r; j++)
                brute[j] += delta;
        } else if (op == 1) {
            // 区间查询和操作
            auto res = tree.query(l, r);
            Tp sum = get<0>(res);
            Tp bruteSum = 0;
            for (int j = l; j <= r; j++)
                bruteSum += brute[j];
            assert(sum == bruteSum);
        } else if (op == 2) {
            // 区间查询最大值操作
            auto res = tree.query(l, r);
            Tp mx = get<2>(res);
            Tp bruteMax = *max_element(brute.begin() + l, brute.begin() + r + 1);
            assert(mx == bruteMax);
        } else {
            // 区间查询最小值操作
            auto res = tree.query(l, r);
            Tp mn = get<1>(res);
            Tp bruteMin = *min_element(brute.begin() + l, brute.begin() + r + 1);
            assert(mn == bruteMin);
        }
    }
    cout << "passed!\n";
}
int main() {
    int u = 10;
    while (u--) test<int>();
    u = 10;
    while (u--) test<int64_t>();
}
