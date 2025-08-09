struct dsu {
    vector<int> p; // father
    vector<int> s; // size
    long long cur = 0; // num of edge
    long long calc(long long x) {
        return x * (x - 1) / 2;
    }
    dsu(int n) : p(n + 1), s(n + 1, 1) { 
        iota(p.begin(), p.end(), 0); 
    }
    int find(int x) { 
        return p[x] == x ? x : p[x] = f(p[x]); 
    }
    void unite(int x, int y) { 
        int f1 = find(x), f2 = find(y);
        long long n1 = s[f1], n2 = s[f2];
        cur -= calc(n2) + calc(n1);
        cur += calc(n1 + n2);
        p[f2] = f1;
        s[f1] += s[f2];
    }
    bool equal(int x, int y) { 
        return find(x) == find(y); 
    }
};