template <typename T, typename U>
T ceil(T x, U y) {
    return (x > 0 ? (x + y - 1) / y : x / y);
}
template <typename T, typename U>
T floor(T x, U y) {
    return (x > 0 ? x / y : (x - y + 1) / y);
}
template <typename t, typename u>
pair<t, t> Div(t x, u y) {
    t q = floor(x, y);
    return {q, x - q * y};
}