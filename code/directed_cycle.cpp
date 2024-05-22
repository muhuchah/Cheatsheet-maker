vector<int> color, parent, cycle;
int cycle_start, cycle_end;
bool dfs(int u) {
    color[u] = 1;
    for (auto &v : adj[u]) {
        if (color[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return true;
        } 
        else if (color[v] == 1) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }
    color[u] = 2;
    return false;
}
bool find_cycle(int n) {
    cycle.clear();
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;
    for (int u = 0; u < n; u++) 
        if (color[u] == 0 && dfs(u)) break;
    if (cycle_start == -1) return false;
    cycle.push_back(cycle_start);
    for (int u = cycle_end; u != cycle_start; u = parent[u])
        cycle.push_back(u);
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    return true;
}
