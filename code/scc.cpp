vector<int> order, component, root_nodes, roots(N), adj_scc[N];
void dfs1(int u) {
    vis[u] = true;
    for (auto &v : adj[u])
        if (!vis[v]) dfs1(v);
    order.push_back(u);
}
void dfs2(int u) {
    vis[u] = true;
    component.push_back(u);
    for (auto &v : adj_rev[u]) 
        if (!vis[v]) dfs2(v);
}
void scc(int n) {
    order.clear();
    root_nodes.clear();
    for (int u = 0; u < n; u++)
        if (!vis[u]) dfs1(u);
    reverse(order.begin(), order.end());
    fill(vis, vis + n, false);
    for (auto &u : order) {
        if (!vis[u]) {
            dfs2(u);
            int root = component.front();
            for (auto &v : component)
                roots[v] = root;
            root_nodes.push_back(root);
            adj_scc[root].clear();
            component.clear();
        }
    }
    for (int u = 0; u < n; u++) {
        for (auto &v : adj[u]) {
            int root_u = roots[u], root_v = roots[v];
            if (root_u != root_v)
                adj_scc[root_u].push_back(root_v);
        }
    }
}
