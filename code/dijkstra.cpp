const ll INF = 4e18;
ll d[N], p[N], cnt[N];
void dij(int s, int n) { // O(m*log(n))
    fill(d, d + n, INF);
    fill(p, p + n, -1);
    fill(cnt, cnt + n, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, s});
    d[s] = 0; cnt[s] = 1;
    while (!q.empty()) {
        auto [d_u, u] = q.top(); q.pop();
        if (d_u != d[u]) continue;
        for (auto &e : adj[u]) {
            auto [v, w] = e;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                p[v] = u;
                cnt[v] = cnt[u];
                q.push({d[v], v});
            }
            else if (d[u] + w == d[v])
                cnt[v] = (cnt[v] + cnt[u]);
        }
    }
}
