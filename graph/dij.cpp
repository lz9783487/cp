vector<int> dis, vis;
priority_queue<T, vector<T>, greater<T>> pq;

dis[start] = ...;
pq.emplace(dis[start], start);

while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (vis[u]) continue;
    vis[u] = 1; // 如果不适用vis，只是用dis判断，可能由多个dis[u]相等的u点进入堆，导致u点重复扩展多次
    for (auto i : g[u]) {
        if (dis[v] > dis[u] + D(u, v)) {
            dis[v] = dis[u] + D(u, v);
            pq.emplace(dis[v], v);
        }
    }
}
