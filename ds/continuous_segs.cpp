template <typename T = int, typename seg_type = pair<T, T>>
struct Segs { // 维护连续区间
    static const T inf = (int) 1e9 + 5;
    // static const T inf = (T) 1e18 + 5;
    static bool is_intersect(T l1, T r1, T l2, T r2) { // 相交
        return !(l2 > r1 or r2 < l1);
    }
    static bool is_share_side(T l1, T r1, T l2, T r2) { // 相邻
        return l2 == r1 + 1 or r2 == l1 - 1;
    }
    static bool is_is(T l1, T r1, T l2, T r2) {
        return is_intersect(l1, r1, l2, r2) or is_share_side(l1, r1, l2, r2);
    }
    using seg_iterator = typename set<seg_type>::iterator;
    set<seg_type> segs;
    void add(T l, T r) { // 闭区间
        auto it = find_isis(l, r);
        while (it != segs.end()) {
            T x = it->first, y = it->second;
            if (is_is(x, y, l, r)) {
                l = min(l, x), r = max(r, y);
                ++it;
                segs.erase({x, y});
            } else {
                break;
            }
        }
        segs.emplace(l, r);
    }
    void remove(T l, T r) { // 闭区间
        auto insert = [&](T l, T r) {
            if (r >= l) {
                segs.emplace(l, r);
            }
        };
        auto split = [&](T p) -> void {
            auto it = find(p);
            if (it != segs.end()) {
                T x = it->first, y = it->second;
                segs.erase(it);
                insert(x, p - 1);
                insert(p, p);
                insert(p + 1, y);
            }
        };
        split(l);
        split(r);
        auto it = segs.lower_bound({l, l});
        while (it != segs.end()) {
            auto [x, y] = *it;
            if (x > r) {
                break;
            } else {
                ++it;
                segs.erase({x, y});
            }
        }
    }
    seg_iterator find(T p) { // 返回与点p有交集的iterator(显然这样的iterator个数<=1)
        auto it = segs.upper_bound({p, inf});
        if (it != segs.begin()) {
            --it;
            auto [x, y] = *it;
            if (y >= p) {
                return it;
            }
        }
        return segs.end();
    }
    seg_iterator find(T l, T r) { // 返回与[l, r]有交集的最左侧的的iterator
        auto re = find(l);
        if (re != segs.end()) { // 与左端点有交集的区间
            return re;
        } else {
            auto it = segs.upper_bound({l, l});
            if (it != segs.end() && it->first <= r) {
                return it;
            } else {
                return segs.end();
            }
        }
    }
    seg_iterator find_isis(T l, T r) { // 最左侧的满足isis的iterator
        auto re = segs.end();
        auto it = segs.lower_bound({l, l});
        while (true) {
            if (it != segs.end()) {
                T x = it->first, y = it->second;
                if (is_is(x, y, l, r)) {
                    re = it;
                } else if (y < l - 1) {
                    break;
                }
            }
            if (it == segs.begin()) {
                break;
            }
            --it;
        }
        return re;
    }

};