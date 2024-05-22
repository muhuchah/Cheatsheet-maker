const ll INF = 4e18;
ll d[N], cnt[N]; bool inq[N];
// false -> exist negative cycle
bool spfa(int s, int n) { // O(n*m)
    fill(d, d + n, INF);
    fill(cnt, cnt + n, 0);
    fill(inq, inq + n, 0);
    queue<int> q; q.push(s);
    d[s] = 0; inq[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = false;
        for (auto &e : adj[u]) {
            auto [v, w] = e.first;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (!inq[v]) {
                    q.push(v); inq[v] = true;
                    cnt[v]++;
                    if (cnt[v] > n) return false; 
                }
            }
        }
    }
    return true;
}
