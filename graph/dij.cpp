using T = pair<int, int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> g;
    vector<int> dis, vis;
    priority_queue<T, vector<T>, greater<T>> pq;

    dis[0] = ...;
    pq.emplace(0, dis[0]);
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1; // 如果不适用vis，只是用dis判断，可能由多个dis[u]相等的u点进入堆，导致u点重复扩展多次
        for (auto i : g[u]) {
            if (dis[i] > dis[u] + D(u, i)) {
                dis[i] = dis[u] + D(u, i);
                pq.emplace(i, dis[i]);
            }
        }
    }
    return 0;
}