const int64_t inf = (int64_t) 1e18;
struct Segtree {
    vector<int64_t> seg;

    Segtree(int n) {
        seg = vector<int64_t>(n * 4 + 1, inf);
    }

    int64_t compose(int64_t info0, int64_t info1) {
        return min(info0, info1);
    }

    void update(int id) {
        seg[id] = compose(seg[id * 2], seg[id * 2 + 1]);
    }

    void modify(int id, int l, int r, int pos, int64_t value) {
        if (l == pos && r == pos) {
            seg[id] = min(seg[id], value);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) modify(id * 2, l, mid, pos, value);
        else modify(id * 2 + 1, mid + 1, r, pos, value);
        update(id);
    }

    int64_t query(int id, int l, int r, int query_l, int query_r) {
        if (l == query_l && r == query_r) return seg[id];
        int mid = (l + r) / 2;
        if (query_r <= mid) return query(id * 2, l, mid, query_l, query_r);
        else if (query_l > mid) return query(id * 2 + 1, mid + 1, r, query_l, query_r);
        else {
            return compose(query(id * 2, l, mid, query_l, mid), query(id * 2 + 1, mid + 1, r, mid + 1, query_r));
        }
    }
};