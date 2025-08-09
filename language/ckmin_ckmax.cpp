template <typename A, typename B>
bool ckmn(A &x, const B &y) {
    return x > y && (x = y, true);
}
template <typename A, typename B>
bool ckmx(A &x, const B &y) {
    return x < y && (x = y, true);
}