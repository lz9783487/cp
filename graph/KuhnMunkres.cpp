#include <tool/tool.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define xding(x) priority_queue<x, vector<x>, greater<x> >
#define dding(x) priority_queue<x, vector<x>, less<x> >
#define fb(x,a,b) for(long long x = (a); x <= (b); ++x)
#define fk(x,a,b) for(long long x = (a); x < (b); ++x)
#define rall(x) x.rbegin(),x.rend()
#define eh(x,y) for(auto &x : y)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define pb push_back
#define ins insert
#define se second
#define fi first
#define V vector

using namespace std;
typedef vector<pair<long long, long long> > vpll;
typedef vector<vector<vector<int> > > vvvi;
typedef pair<long long, long long> pll;
typedef vector<pair<int, int> > vpii;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long double ld;
typedef long long ll;
typedef double db;

const char end1 = '\n';
const int N = (int)503;
int con[N][N]; // 临界矩阵
int n, m, e;
int zuomatch[N]; // zuomatch[i] = j表示左侧的第i个与右侧的第j的相匹配了
int youmatch[N]; // 同上
int qian[N];
int ischeck[N]; // 用于记录右侧节点是否被检查过
int main() {
    ios::sync_with_stdio(!cin.tie(0));
    memset(zuomatch, -1, sizeof zuomatch);
    memset(youmatch, -1, sizeof youmatch);
    memset(qian, -1, sizeof qian);
    memset(ischeck, -1, sizeof ischeck);
    cin >> n >> m >> e; // 左侧节点数, 右侧节点数, 边数
    int a, b;
    while (e--) { // 邻接矩阵
        cin >> a >> b; // 左侧的a可以与右侧的b相连
        con[a][b] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        queue<int> Q;
        Q.push(i);
        int you = 0;
        while (Q.size() && you == 0) {
            int u = Q.front(); Q.pop(); // u是当前左侧节点
            for (int v = 1; v <= m && you == 0; ++v) { // v是与u相连的右侧节点
                if (con[u][v] == 0 || ischeck[v] == i) continue; // ischeck[v] == i, 表示v节点在第i轮被访问过, 第i论就是本轮
                ischeck[v] = i;
                if (youmatch[v] != -1) { // 节点v已经被匹配了
                    qian[youmatch[v]] = u; // 记录youmatch[v]是因谁而被迫入队的
                    Q.push(youmatch[v]);
                } else {
                    you = 1;
                    while (u != -1) {
                        int z = zuomatch[u];
                        zuomatch[u] = v, youmatch[v] = u;
                        u = qian[u], v = z; // u永远是左侧节点, v永远是右侧节点
                    }
                }
            }
        }
        ans += you;
    }
    cout << ans << end1;
    return 0;
}




  