struct Edge {
    int u, v, w;
    bool operator < (Edge const &other)
        return w < other.w;
} edges[N]; vector<Edge> result;
// -1 -> not exitst mst
ll kruskal(int n, int m) { // O(m*log(n))
    result.clear();
    ll total_weight = 0;
    sort(edges, edges + m);
    dsu d(n);
    int nodes = 0;
    for (auto &e : edges) {
        if (!d.same(e.u, e.v)) {
            total_weight += e.w;
            result.push_back(e);
            d.merge(e.u, e.v);
            nodes++;
        }
        if (nodes == n - 1) break;
    }
    if (nodes != n - 1) return -1;
    return total_weight;
}
