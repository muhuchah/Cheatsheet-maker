vector<int> tin, low, art_points;
int timer;
void dfs(int u, int p = -1) {
    vis[u] = true;
    tin[u] = low[u] = timer++;
    int children = 0;
    for (int &v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) low[u] = min(low[u], tin[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1)
                art_points.push_back(u);
            children++;
        }
    }
    if (p == -1 && children > 1)
        art_points.push_back(u);
}
void find_art_points(int n) {
    art_points.clear();
    tin.assign(n, -1);
    low.assign(n, -1);
    timer = 0;
    for (int u = 0; u < n; u++) 
        if (!vis[u]) dfs(u);
    sort(art_points.begin(), art_points.end());
    art_points.erase(unique(art_points.begin(), art_points.end()), art_points.end());
}
