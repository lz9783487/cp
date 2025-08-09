struct segtree_d {

    using ll = long long;
    const ll mod = 1000000007;
    struct tag {
        ll mul, add;
    };

    tag compose(const tag &t1, const tag &t2) {
        // (x * t1.mul + t1.add) * t2.mul + t2.add
        return {t1.mul * t2.mul % mod, (t1.add * t2.mul + t2.add) % mod};
    }

    struct node {
        tag t;
        ll val;
        int sz;
    };
    vector<node> seg;

    segtree_d(int n) {
        seg = vector<node>(n * 4 + 5);
    }

    void update(int id) {
        seg[id].val = (seg[id * 2].val + seg[id * 2 + 1].val) % mod; 
        // 合并两孩子节点tag的时候，注意防止被孩子污染
        // 即：不要写成father = compose(son_left, son_right)，此时有可能会误用孩子的tag
    }

    void settag(int id, tag t) {
        seg[id].t = compose(seg[id].t, t);
        seg[id].val = (seg[id].val * t.mul + seg[id].sz * t.add) % mod;
    }

    void pushdown(int id) {
        if (seg[id].t.mul != 1 || seg[id].t.add != 0) { // 标记非空
            settag(id * 2, seg[id].t);
            settag(id * 2 + 1, seg[id].t);
            seg[id].t.mul = 1;
            seg[id].t.add = 0;
        }
    }

    void build(int id, int l, int r, const vector<int> &a) {
        seg[id].t = {1, 0};
        seg[id].sz = r - l + 1;
        if (l == r) {
            seg[id].val = {a[l]};
        } else {
            int mid = (l + r) / 2;
            build(id * 2, l, mid, a);
            build(id * 2 + 1, mid + 1, r, a);
            update(id);
        }
    }

    // 节点为id，对应的区间为[l, r]，修改a[pos] -> val
    void modify(int id, int l, int r, int ql, int qr, tag t) {
        if (l == ql && r == qr) {
            settag(id, t);
            return;
        }
        int mid = (l + r) / 2;
        // 重要‼️
        pushdown(id);
        if (qr <= mid) modify(id * 2, l, mid, ql, qr, t);
        else if (ql > mid) modify(id * 2 + 1, mid + 1, r, ql, qr, t);
        else {
            modify(id * 2, l, mid, ql, mid, t);
            modify(id * 2 + 1, mid + 1, r, mid + 1, qr, t);
        }
        // 重要‼️
        update(id);
    }

    // [ql, qr]表示查询的区间
    ll query(int id, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) return seg[id].val;
        int mid = (l + r) / 2;
        // 重要‼️
        pushdown(id);
        if (qr <= mid) return query(id * 2, l, mid, ql, qr);
        else if (ql > mid) return query(id * 2 + 1, mid + 1, r, ql, qr);
        else {
            // qr > mid, ql <= mid
            // [ql, mid], [mid + 1, qr]
            return (query(id * 2, l, mid, ql, mid) + query(id * 2 + 1, mid + 1, r, mid + 1, qr)) % mod;
        }
    }
};