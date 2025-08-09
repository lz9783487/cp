// ___shupou
#include <bits/stdc++.h>
using namespace std;
// declaration
string to_string(char);
string to_string(char*);
string to_string(bool);
string to_string(string);
template <typename A, typename B>
string to_string(pair<A, B>);
template <typename T>
string to_string(priority_queue<T>);
template <typename T>
string to_string(stack<T>);
template <typename T>
string to_string(queue<T> x);
template <typename T>
string to_string(T x);
// implementation
string to_string(char x) {
    return "'" + string() + x + "'";
}
string to_string(const char* s) {
    return string(s);
}
string to_string(bool x) {
    if (x) return "true";
    else return "false";
}
string to_string(string s) {
    return "\"" + s + "\"";
}
template <typename A, typename B>
string to_string(pair<A, B> x) {
    return "(" + to_string(x.first) + ", " + to_string(x.second) + ")";
}
template <typename T>
string to_string(priority_queue<T> x) {
    vector<T> v;
    while (!x.empty()) {
        v.push_back(x.top());
        x.pop();
    }
    return to_string(v);
}
template <typename T>
string to_string(stack<T> x) {
    vector<T> v;
    while (!x.empty()) {
        v.push_back(x.top());
        x.pop();
    }
    return to_string(v);
}
template <typename T>
string to_string(queue<T> x) {
    vector<T> v;
    while (!x.empty()) {
        v.push_back(x.front());
        x.pop();
    }
    return to_string(v);
}
template <typename T>
string to_string(T v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#define fuck(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define fi first
#define se second
#define ins insert
#define pb push_back
#define em emplace
#define eb emplace_back
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define send {ios::sync_with_stdio(0);}
#define help {cin.tie(0);}
#define fn0(x) for (int i = 0; i < x; ++i)
#define fn1(x) for (int i = 1; i <= x; ++i)
#define nf1(x) for (int i = (x); i >= 1; --i)
#define nf0(x) for (int i = (x - 1); i >= 0; --i)
#define fsz(i, a) for (int i = 0; i < sz(a); ++i)
#define fk(i, a, b) for (int i = (a); i < (b); ++i)
#define fb(i, a, b) for (int i = (a); i <= (b); ++i)
#define fan(i, a, b) for (int i = (a); i >= (b); --i)
#define eh(i, x) for (auto& i : x)
using namespace std;
using i32 = int;
using ll = long long;
using i64 = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using si = set<int>;
using sl = set<ll>;
using mii = map<int, int>;
using mll = map<ll, ll>;
template <typename T>
using S = set<T>;
template <typename T>
using V = vector<T>;
template <typename T>
using Q = queue<T>;
template <typename T>
using DQ = deque<T>;
template <typename T>
using ST = stack<T>;
template <typename T, typename _T>
using MP = map<T, _T>;
template <typename T, typename _T>
using P = pair<T, _T>;
template <typename T>
using DAP = priority_queue<T, vector<T>, less<T>>;
template <typename T>
using XIP = priority_queue<T, vector<T>, greater<T>>;
using vvi = V<vi>;
using vvl = V<vl>;
using vvvi = V<vvi>;
using vvvl = V<vvl>;
using vpii = V<pii>;
using vpll = V<pll>;
template <typename T>
ll Min(T a) {
    return (ll)a;
}
template <typename Head, typename... Tail>
ll Min(Head H, Tail... T) {
    return min((ll)H, Min(T...));
}
template <typename T>
ll Max(T a) {
    return (ll)a;
}
template <typename Head, typename... Tail>
ll Max(Head H, Tail... T) {
    return max((ll)H, Max(T...));
}
template <typename T>
ll Gcd(T a) {
    return a;
}
template <typename Head, typename... Tail>
ll Gcd(Head H, Tail... T) {
    return __gcd((ll)H, Gcd(T...));
}
// declaration
template <typename T> void cao(T);
template <typename T> void cao(vector<T>&);
template <typename T> void cao(set<T>&);
template <typename A, typename... B> void cao(A, B...);
// implementation
template <typename T>
void cao(T x) {
    cout << x << '\n';
}
template <typename T>
void cao(vector<T>& x) {
    bool is = false;
    for (auto& i : x) {
        if (is) cout << ' ';
        is = true;
        cout << i;
    }
    cout << '\n';
}
template <typename T>
void cao(set<T>& a) {
    bool is = false;
    for (auto& i : a) {
        if (is) cout << ' ';
        is = true;
        cout << i;
    }
    cout << '\n';
}
template <typename Head, typename... Tail>
void cao(Head H, Tail... T) {
    cout << H << ' ';
    cao(T...);
}
// declaration
template <typename T> istream& operator >> (istream&, set<T>&);
template <typename T> istream& operator >> (istream&, vector<T>&);
template <typename A, typename B> istream& operator >> (istream&, P<A, B>&);
// implementation
template <typename T>
istream& operator >> (istream& in, vector<T>& x) {
    for (auto& i : x) in >> i;
    return in;
}
template <typename A, typename B>
istream& operator >> (istream& in, P<A, B>& x) {
    in >> x.fi >> x.se;
    return in;
}
// declaration
template <typename T> void Cin(T&);
template <typename A, typename... B> void Cin(A&, B&...);
// implementation
template <typename T>
void Cin(T& x) {
    cin >> x;
}
template <typename A, typename... B>
void Cin(A& a, B&... b) {
    cin >> a;
    Cin(b...);
}
const char end1 = '\n';//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int N = (int)1e5 + 5;
#define lowbit(x) ((x)&(-x))
ll sum1[N];
ll sum2[N];
void update(int p, ll dx)
{
    for (ll i = p; i < N; i += lowbit(i))
    {
        sum1[i] += dx;
        sum2[i] += p * dx;
    }
}
void update(int l, int r, ll dx)
{
    update(l, dx), update(r + 1, -dx);
}
ll query(int p)
{
    ll res = 0;
    for (ll i = p; i > 0; i -= lowbit(i))
    {
        res += (p + 1) * sum1[i] - sum2[i];
    }
    return res;
}
ll query(int l, int r)
{
    return query(r) - query(l - 1);
}
ll mod;
const int maxn = (int)1e5 + 5;
vi G[maxn];
int w[maxn];
int dep[maxn], fa[maxn], son[maxn], siz[maxn];
int dfn[maxn], tt;
int id[maxn];
int top[maxn];
void dfs1(int u) {
    siz[u] = 1;
    for (int k = 0; k < sz(G[u]); k++) {
        int v = G[u][k];
        if (v == fa[u]) continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        dfs1(v);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) {
            son[u] = v;
        }
    }
}
void dfs2(int u, int x) {
    dfn[u] = ++tt;
    id[tt] = u;
    top[u] = x;
    if (!son[u]) return;
    dfs2(son[u], x);
    for (int k = 0; k < sz(G[u]); k++) {
        int v = G[u][k];
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
ll qTree(int u) {
    return query(dfn[u], dfn[u] + siz[u] - 1);
}
void uTree(int u, int dx) {
    update(dfn[u], dfn[u] + siz[u] - 1, dx);
}
ll qPath(int u, int v) {
    ll ans = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        ans = (ans + query(dfn[top[u]], dfn[u])) % mod;
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    ans = (ans + query(dfn[u], dfn[v])) % mod;
    return ans;
}
void uPath(int u, int v, int dx) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        update(dfn[top[u]], dfn[u], dx);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    update(dfn[u], dfn[v], dx);
}
int main() {
    send help
    int n, m, r;
    cin >> n >> m >> r >> mod;
    ll wei[maxn];
    fb (i, 1, n) cin >> wei[i];
    int u, v;
    fb (i, 1, n - 1) {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs1(r);
    dfs2(r, r);
    vi init(n + 5);
    fb (i, 1, n) {
        init[dfn[i]] = wei[i];
    }
    fan (i, n, 1) {
        init[i] -= init[i - 1];
    }
    fb (i, 1, n) {
        update(i, init[i]);
    }
    int op, z;
    while (m--) {
        cin >> op;
        switch (op) {
            case 1: {
                cin >> u >> v >> z;
                uPath(u, v, z);
                break;
            }
            case 2: {
                cin >> u >> v;
                cao(ll(qPath(u, v) % mod));
                break;
            }
            case 3: {
                cin >> u >> z;
                uTree(u, z);
                break;
            }
            case 4: {
                cin >> u;
                cao(ll(qTree(u) % mod));
                break;
            }
        }
    }
    return 0;
}













