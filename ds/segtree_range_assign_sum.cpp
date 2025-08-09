const int inf = (int) 1e9; 
struct T {
    T(int n) { // [1, n]
        root = 0;
        build(root, 1, n);
    }
    int query(int l, int r) { // [l, r]
        return Q(root, l, r);
    }
    void update(int l, int r, int x) { // [l, r]
        return U(root, l, r, x);
    }
private:
    struct Node {
        int l = 0, r = 0, sm = 0, lz = inf; // -1 表示没有懒标记
        Node *ls = 0, *rs = 0;
    } *root;
    void build(Node*& p, int l, int r) {
        p = new Node();
        p->l = l;
        p->r = r;
        if (l != r) {
            int mid = (l + r) >> 1;
            build(p->ls, l, mid);
            build(p->rs, mid + 1, r);
        }
    }
    void xx(Node*&p, int x) {
        p->sm = (p->r - p->l + 1) * x;
        p->lz = x;
    }
    void xia(Node*& p) {
        if (p->lz == inf) {
            return;
        }
        xx(p->ls, p->lz);
        xx(p->rs, p->lz);
        p->lz = inf;
    }
    int Q(Node*& p, int l, int r) {
        if (p->l > r || p->r < l) {
            return 0;
        }
        if (l <= p->l && r >= p->r) {
            return p->sm;
        } else {
            xia(p);
            return Q(p->ls, l, r) + Q(p->rs, l, r);
        }
    }
    void U(Node*& p, int l, int r, int x) {
        if (p->l > r || p->r < l) {
            return;
        }
        if (l <= p->l && r >= p->r) {
            xx(p, x);
        } else {
            xia(p);
            U(p->ls, l, r, x);
            U(p->rs, l, r, x);
            p->sm = p->ls->sm + p->rs->sm;
        }
    }
};
void test() {
    int n, m;
    cin >> n >> m;
    T t(n);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        t.update(i, i, x);
    }
    while (m--) {
        int o;
        cin >> o;
        if (o == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            t.update(l, r, k);
        } else {
            int l, r;
            cin >> l >> r;
            cout << t.query(l, r) << '\n';
        }
    }
}
