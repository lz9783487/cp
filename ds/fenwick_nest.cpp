template <typename T>
struct fenwick {
    vector<T> a;
    void init(int n) {  // [0, n)
        assert(n >= 1);
        a = vector<T>(n + 1, 0);
    }
    void update(int p, T delta) {  // p in [0, n)
        p += 1;
        for (; p < (int)a.size(); p += p & (-p)) {
            a[p] += delta;
        }
    }
    T query(int p) {  // [0, p)
        if (p < 0) {
            return 0;
        }
        T res = 0;
        for (; p; p -= p & -p) {
            res += a[p];
        }
        return res;
    }
};
template <typename T>
struct fenwick_nest {
    fenwick<T> d, id;
    void init(int n) {
        d.init(n);
        id.init(n);
    }
    void update(int l, int r, T x) {  // update: [l, r)
        d.update(l, x);
        id.update(l, x * l);
        if (r < (int)d.a.size()) {
            d.update(r, -x);
            id.update(r, r * -x);
        }
    }
    T query(int l, int r) {  // query on [l, r)
        T sm1 = l * d.query(l) - id.query(l);
        T sm2 = r * d.query(r) - id.query(r);
        return sm2 - sm1;
    }
};
void test_Fenwick2() {
    const int n = 10;
    const int T = 10000;
    mt19937 mt(std::random_device{}());
    fenwick_nest<long long> fenwickTree;
    fenwickTree.init(n);
    vector<long long> arr(n, 0);
    auto mtrand = [&](int l, int r) {
        std::uniform_int_distribution<> uid(l, r - 1);
        return uid(mt);
    };
    for (int t = 0; t < T; t++) {
        int l = mtrand(0, n);
        int r = mtrand(0, n);
        if (l > r) {
            swap(l, r);
        }
        ++r;
        if (mtrand(0, 2) % 2) {
            long long value = mtrand(0, 2000) - 1000;
            fenwickTree.update(l, r, value);
            for (int i = l; i < r; ++i) {
                arr[i] += value;
            }
        } else {
            long long simpleArraySum = 0;
            for (int i = l; i < r; i++) {
                simpleArraySum += arr[i];
            }
            assert(fenwickTree.query(l, r) == simpleArraySum);
        }
    }
    cout << "All tests passed!" << endl;
}