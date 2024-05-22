vector<int> parent, cycle;
int cycle_start, cycle_end;
bool dfs(int u, int p) {
    vis[u] = true;
    for (auto &v : adj[u]) {
        if(v == p) continue; 
        if (vis[v]) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
        parent[v] = u;
        if (dfs(v, parent[v])) return true;
    }
    return false;
}
bool find_cycle(int n) {
    cycle.clear();
    parent.assign(n, -1);
    cycle_start = -1;
    for (int u = 0; u < n; u++)
        if (!vis[u] && dfs(u, parent[u]))
            break;
    if (cycle_start == -1) return false;
    cycle.push_back(cycle_start);
    for (int u = cycle_end; u != cycle_start; u = parent[u]) 
        cycle.push_back(u);
    cycle.push_back(cycle_start);
    return true;
}
