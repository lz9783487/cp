template <typename T>
struct fenwick {
    vector<T> a;
    void init(int n) { // [0, n)
        assert(n >= 1);
        a = vector<T>(n + 1, 0);
    }
    void update(int p, T delta) { // p in [0, n)
        p += 1;
        for (; p < (int) a.size(); p += p & (-p)) {
            a[p] += delta;
        }
    } 
    T query(int p) { // [0, p)
        if (p < 0) {
            return 0;
        }
        T res = 0;
        for (; p; p -= p & -p) {
            res += a[p];
        }
        return res;
    }
    void set(int p, T x) { // single point
        update(p, x - get(p));
    }
    T get(int p) { // single point
        return query(p + 1) - query(p);
    }
    int max_length(T s) { // max length of a[0] + a[1] + ... <= s
        int pos = 0;
        int topbit = 31 - __builtin_clz(a.size() - 1);
        for (int j = topbit; j >= 0; j--) {
            if (pos + (1 << j) < (int) a.size() && a[pos + (1 << j)] <= s) {
                pos += (1 << j);
                s -= a[pos];
            }
        }
        return pos;
    }
};
