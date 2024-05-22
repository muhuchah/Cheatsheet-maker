vector<pair<int, int>> bridges;
vector<int> tin, low;
int timer;
void dfs(int u, int p = -1) {
    vis[u] = true;
    tin[u] = low[u] = timer++;
    for (auto &v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) 
            low[u] = min(low[u], tin[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u])
                bridges.push_back({u, v});
        }
    }
}
void find_bridges(int n) {
    bridges.clear();
    tin.assign(n, -1);
    low.assign(n, -1);
    timer = 0;
    for (int u = 0; u < n; u++) 
        if (!vis[u]) dfs(u);
}
