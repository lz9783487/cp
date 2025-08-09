#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 101000;
vector<pair<int, int>> e[N];

int dfn[N], low[N], ins[N], bel[N], cnt, idx, n, m;
vector<int> cc[N];
stack<int> stk;

void dfs(int u, int id) {
	dfn[u] = low[u] = ++idx;
	ins[u] = true;
	stk.push(u);

	for (auto [v, id2] : e[u]) {
		if (!dfn[v]) {
			dfs(v, id2);
			low[u] = min(low[u], low[v]);
		} else if (id != id2) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		++cnt;
		while (true) {
			int v = stk.top();
			cc[cnt].push_back(v);
			ins[v] = false;
			bel[v] = cnt;
			stk.pop();
			if (v == u) break;
		}
	}

}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back({v, i});
		e[v].push_back({u, i});
	}
	dfs(1, -1);
	int nleaf = 0;
	for (int i = 1; i <= cnt; i++) { // me:遍历所有的边双联通分量
		int cnte = 0;
		for (auto u : cc[i]) { // me:遍历该边双联通分量的每个点u
			for (auto [v, id] : e[u]) // me:遍历其邻接点v
				cnte += (bel[u] != bel[v]); // me:判断uv是否同属于一个联通分量
		}
		nleaf += (cnte == 1); // me:如果该边双联通分量与外界只有一次联系，那么它就是叶子（这里也考虑到了孤独的根节点）
	}
	printf("%d\n", (nleaf + 1) / 2); // me:等价于：每次能够选择一条路径去染色，几次之后能够染色整棵树
}
