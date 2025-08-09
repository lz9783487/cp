#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
    #include <other/debug.h>
#else
    #define debug(...) 0
#endif
using namespace std;
template <typename A, typename B>
bool ckmn(A &x, const B &y) {
    return x > y && (x = y, true);
}
template <typename A, typename B>
bool ckmx(A &x, const B &y) {
    return x < y && (x = y, true);
}
template <typename A, typename B>
istream &operator>>(istream &in, pair<A, B> &p) {
    in >> p.first >> p.second;
    return in;
}
template <typename T>
concept ListOrVector = is_same_v<T, list<typename T::value_type>> or is_same_v<T, vector<typename T::value_type>>;
template <ListOrVector T>
istream &operator>>(istream &in, T &p) {
    for (auto &i : p) in >> i;
    return in;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    os << p.first << ' ' << p.second;
    return os;
}
template <ListOrVector T>
ostream &operator<<(ostream &os, const T &container) {
    for (auto it = begin(container); it != end(container); ++it) {
        if (it != begin(container)) os << ' ';
        os << *it;
    }
    return os;
}
template <typename T>
vector<int> index_sort(const vector<T> &A) {  // stable index sort
    vector<int> ids(A.size());
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) {
        if (A[i] == A[j]) {
            return i < j;
        } else {
            return A[i] < A[j];
        }
    });
    return ids;
}
template <typename F>
int64_t bs(F check, int64_t ok, int64_t ng, bool check_ok = true) {
    // F(ok) = 1, F(ng) = 0
    if (check_ok) {
        assert(check(ok));
        assert(!check(ng));
    }
    while (abs(ok - ng) > 1) {
        auto x = (ng + ok) / 2;
        tie(ok, ng) = (check(x) ? make_pair(x, ng) : make_pair(ok, x));
    }
    return ok;
}
template <typename F>
double bsr(F check, double ok, double ng, int iter = 100) {
    while (iter--) {
        double x = (ok + ng) / 2;
        tie(ok, ng) = (check(x) ? make_pair(x, ng) : make_pair(ok, x));
    }
    return (ok + ng) / 2;
}
template <typename T, typename U>
T ceil(T x, U y) {
    return (x > 0 ? (x + y - 1) / y : x / y);
}
template <typename T, typename U>
T floor(T x, U y) {
    return (x > 0 ? x / y : (x - y + 1) / y);
}
template <typename t, typename u>
pair<t, t> div(t x, u y) {
    t q = floor(x, y);
    return {q, x - q * y};
}
int topbit(uint64_t x) {
    return (x == 0 ? -1 : 63 - countl_zero(x));
}
int lowbit(uint64_t x) {
    return (x == 0 ? -1 : countr_zero(x));
}
int popcount(int64_t x) {
    return popcount((uint64_t)x);
}
template <typename T>
using V = vector<T>;
template <typename T>
using VV = V<V<T>>;
template <typename T>
using VVV = V<VV<T>>;
template <typename T>
using VVVV = V<VVV<T>>;
template <typename T>
using dd = priority_queue<T, V<T>, less<T>>;
template <typename T>
using xd = priority_queue<T, V<T>, greater<T>>;
using sr = string;
using db = double;
using ld = long double;
using ll = long long;
using ull = unsigned long long;
using si = set<int>;
using sl = set<ll>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using spii = set<pii>;
using spll = set<pll>;
using vpii = V<pii>;
using vpll = V<pll>;
using vvpii = VV<pii>;
using vvpll = VV<pll>;
using vi = V<int>;
using vvi = VV<int>;
using vvvi = VVV<int>;
using vl = V<ll>;
using vvl = VV<ll>;
using vvvl = VVV<ll>;

#define OVERLOAD5(a, b, c, d, e, ...) e
#define FOR4(i, a, b, c) for (auto i = (a); i < (b); i += (c))
#define FOR1(a) FOR4(_, 0, a, 1)
#define FOR2(i, a) FOR4(i, 0, a, 1)
#define FOR3(i, a, b) FOR4(i, a, b, 1)
#define fk(...) OVERLOAD5(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)  // fk
#define FB4(i, a, b, c) for (auto i = (a); i <= (b); i += (c))
#define FB1(a) FB4(_, 1, a, 1)
#define FB2(i, a) FB4(i, 1, a, 1)
#define FB3(i, a, b) FB4(i, a, b, 1)
#define fb(...) OVERLOAD5(__VA_ARGS__, FB4, FB3, FB2, FB1)(__VA_ARGS__)  // fb
#define FAN4(i, a, b, c) for (auto i = (a); i >= (b); i -= (c))
#define FAN1(a) FAN4(_, a, 0, 1)
#define FAN2(i, a) FAN4(i, a, 0, 1)
#define FAN3(i, a, b) FAN4(i, a, b, 1)
#define fn(...) OVERLOAD5(__VA_ARGS__, FAN4, FAN3, FAN2, FAN1)(__VA_ARGS__)  // fn
#define fors(t, s) for (auto t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))  // for_subset

#define OVERLOAD8(_1, _2, _3, _4, _5, _6, _7, _8, ...) _8
#define EACHA2(a, b, v) a, b
#define EACHA3(a, ...) a, EACHA2(__VA_ARGS__)
#define EACHA4(a, ...) a, EACHA3(__VA_ARGS__)
#define EACHA5(a, ...) a, EACHA4(__VA_ARGS__)
#define EACHZ1(a, v) a
#define EACHZ2(a, b, v) [EACHA2(a, b, v)]
#define EACHZ3(a, ...) [ a, EACHA2(__VA_ARGS__) ]
#define EACHZ4(a, ...) [ a, EACHA3(__VA_ARGS__) ]
#define EACHZ5(a, ...) [ a, EACHA4(__VA_ARGS__) ]
#define EACHZ6(a, ...) [ a, EACHA5(__VA_ARGS__) ]
#define EACHB1(a, v) v
#define EACHB2(a, ...) EACHB1(__VA_ARGS__)
#define EACHB3(a, ...) EACHB2(__VA_ARGS__)
#define EACHB4(a, ...) EACHB3(__VA_ARGS__)
#define EACHB5(a, ...) EACHB4(__VA_ARGS__)
#define EACHB6(a, ...) EACHB5(__VA_ARGS__)
#define EACHA(...) OVERLOAD8(__VA_ARGS__, EACHZ6, EACHZ5, EACHZ4, EACHZ3, EACHZ2, EACHZ1)(__VA_ARGS__)
#define EACHB(...) OVERLOAD8(__VA_ARGS__, EACHB6, EACHB5, EACHB4, EACHB3, EACHB2, EACHB1)(__VA_ARGS__)
#define eh(...) for (auto &&EACHA(__VA_ARGS__) : EACHB(__VA_ARGS__))

#define OVERLOAD7(a, b, c, d, e, f, g, ...) g
#define PR1(a) ::std::cout << (a)
#define PR2(a, ...) PR1(a); PR1(' '); PR1(VA_ARGS )
#define PR3(a, ...) PR1(a); PR1(' '); PR2(__VA_ARGS__)
#define PR4(a, ...) PR1(a); PR1(' '); PR3(__VA_ARGS__)
#define PR5(a, ...) PR1(a); PR1(' '); PR4(__VA_ARGS__)
#define PR6(a, ...) PR1(a); PR1(' '); PR5(__VA_ARGS__)
#define print(...) OVERLOAD7(__VA_ARGS__, PR6, PR5, PR4, PR3, PR2, PR1)(__VA_ARGS__)  // print
#define println(...) print(__VA_ARGS__); PR1('\n')  // print '\n'
#define printendl(...) print(__VA_ARGS__); PR1(::std::endl)  // print endl

#define OVERLOAD20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, NAME, ...) NAME
#define FUNA0(...)
#define FUNA1(T, x) T
#define FUNA2(T, x, ...) T, FUNA1(__VA_ARGS__)
#define FUNA3(T, x, ...) T, FUNA2(__VA_ARGS__)
#define FUNA4(T, x, ...) T, FUNA3(__VA_ARGS__)
#define FUNA5(T, x, ...) T, FUNA4(__VA_ARGS__)
#define FUNA6(T, x, ...) T, FUNA5(__VA_ARGS__)
#define FUNA7(T, x, ...) T, FUNA6(__VA_ARGS__)
#define FUNA8(T, x, ...) T, FUNA7(__VA_ARGS__)
#define FUNA9(T, x, ...) T, FUNA8(__VA_ARGS__)
#define FUNB0(...)
#define FUNB1(T, x) T x
#define FUNB2(T, x, ...) T x, FUNB1(__VA_ARGS__)
#define FUNB3(T, x, ...) T x, FUNB2(__VA_ARGS__)
#define FUNB4(T, x, ...) T x, FUNB3(__VA_ARGS__)
#define FUNB5(T, x, ...) T x, FUNB4(__VA_ARGS__)
#define FUNB6(T, x, ...) T x, FUNB5(__VA_ARGS__)
#define FUNB7(T, x, ...) T x, FUNB6(__VA_ARGS__)
#define FUNB8(T, x, ...) T x, FUNB7(__VA_ARGS__)
#define FUNB9(T, x, ...) T x, FUNB8(__VA_ARGS__)
#define FUNA(...) OVERLOAD20(__VA_ARGS__, FUNA9, FUNA9, FUNA8, FUNA8, FUNA7, FUNA7, FUNA6, FUNA6, FUNA5, FUNA5, FUNA4, FUNA4, FUNA3, FUNA3, FUNA2, FUNA2,FUNA1, FUNA1, FUNA0, FUNA0) (__VA_ARGS__)
#define FUNB(...) OVERLOAD20(__VA_ARGS__, FUNB9, FUNB9, FUNB8, FUNB8, FUNB7, FUNB7, FUNB6, FUNB6, FUNB5, FUNB5, FUNB4, FUNB4, FUNB3, FUNB3, FUNB2, FUNB2, FUNB1, FUNB1, FUNB0, FUNB0) (__VA_ARGS__)
#define fun(R, name, ...) ::std::function<R(FUNA(__VA_ARGS__))> name = [&](FUNB(__VA_ARGS__)) -> R

#define gv1(n0, val) vector(n0, val)
#define gv2(n0, ...) vector(n0, gv1(__VA_ARGS__))
#define gv3(n0, ...) vector(n0, gv2(__VA_ARGS__))
#define gv4(n0, ...) vector(n0, gv3(__VA_ARGS__))
#define gv5(n0, ...) vector(n0, gv4(__VA_ARGS__))
#define gv6(n0, ...) vector(n0, gv5(__VA_ARGS__))
#define GET_GV(_1, _2, _3, _4, _5, _6, _7, NAME, ...) NAME
#define gv(...) GET_GV(__VA_ARGS__, gv6, gv5, gv4, gv3, gv2, gv1)(__VA_ARGS__)  // gen vector
#define ga(a, ...) auto a = gv(__VA_ARGS__)
#define gai(a, ...) auto a = gv(__VA_ARGS__); ii(a)

template <typename T, typename U>
T nsm(const vector<U> &A) {
    T sum = 0;
    for (auto &&a : A) sum += a;
    return sum;
}
template <typename T, typename U>
vector<T> psm(const vector<U> &A, int save0 = 0) {
    size_t N = A.size();
    vector<T> B(N + 1);
    for (size_t i = 0; i < N; ++i) {
        B[i + 1] = B[i] + A[i];
    }
    if (save0 == 0) {
        B.erase(B.begin());
    }
    return B;
}
#define nmn(v) (*min_element(v.begin(), v.end()))
#define nmx(v) (*max_element(v.begin(), v.end()))

#define so(x) sort(all(x))
#define rso(x) sort(rall(x))
#define rv(x) reverse(all(x))
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
#define ii(...) [](auto &..._x_) { (cin >> ... >> _x_); }(__VA_ARGS__)
#define jj(...) __VA_ARGS__; ii(__VA_ARGS__)
#define js ios::sync_with_stdio(false), cin.tie(nullptr)
#define pob pop_back
#define pof pop_front
#define pb push_back
#define eb emplace_back
#define in insert
#define em emplace
#define fi first
#define fif first.first
#define fis first.second
#define se second
#define sef second.first
#define ses second.second
#define ft front
#define bk back
int main() {
    js;
    return 0;
}
