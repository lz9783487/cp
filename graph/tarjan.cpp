#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define send {ios::sync_with_stdio(0);}
#define help {cin.tie(0);}
#define fk(i, a, b) for (int i = (a); i < (b); ++i)
#define fb(i, a, b) for (int i = (a); i <= (b); ++i)
#define fan(i, a, b) for (int i = (a); i >= (b); --i)
#define eh(i, x) for (auto& i : x)
using namespace std;
using vi = vector<int>;
template <typename T>
using V = vector<T>;
template <typename T>
using ST = stack<T>;
const int N = (int) 5e3 + 5;
vi G[N];
ST<int> st;
int inst[N];
int dfn[N];
int low[N];
int _clock = 0;
V<vi> ans;
void tarjan(int p) {
    dfn[p] = low[p] = ++_clock;
    st.push(p);
    inst[p] = 1;
    eh (i, G[p]) {
        if (dfn[i] == 0) {
            tarjan(i);
            low[p] = min(low[p], low[i]);
        }
        else if (inst[i] == 1) {
            low[p] = min(low[p], dfn[i]);
        }
    }
    if (dfn[p] == low[p]) {
        vi z;
        while (1) {
            int tp = st.top();
            st.pop();
            z.pb(tp);
            inst[tp] = 0;
            if (tp == p) break;
        }
        ans.pb(z);
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, c;
    while (m--) {
        scanf("%d %d %d", &a, &b, &c);
        G[a].pb(b);
        if (c == 2) G[b].pb(a);
    }
    fb (i, 1, n) G[0].pb(i);
    tarjan(0);
    eh (i, ans) {
        sort(all(i));
        i.erase(unique(all(i)), i.end());
    }
    // print(ans);
    return 0;
}



