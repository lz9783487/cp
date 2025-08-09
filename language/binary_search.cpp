template <typename F>
int64_t binary_search(F check, int64_t ok, int64_t ng, bool check_ok = true) {
    if (check_ok) {
        assert(check(ok) == true);
        assert(check(ng) == false);
    }
    while (abs(ok - ng) > 1) { // 返回最接近ng的ok
        auto x = (ng + ok) / 2;
        tie(ok, ng) = (check(x) ? make_pair(x, ng) : make_pair(ok, x));
    }
    return ok;
}
template <typename F>
long double binary_search_float(F check, long double ok, long double ng, int iter = 100) {
    while (iter--) {
        double x = (ok + ng) / 2;
        tie(ok, ng) = (check(x) ? make_pair(x, ng) : make_pair(ok, x));
    }
    return (ok + ng) / 2;
}
