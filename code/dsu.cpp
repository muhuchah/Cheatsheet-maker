struct dsu {
    vector<int> parent, sz;
    int c; //connected components
    dsu(int n) : c(0) {
        parent.resize(n); sz.resize(n);
        for (int i = 0; i < n; i++) make(i);
    }
    void make(int a) {
        parent[a] = a;
        sz[a] = 1; c++;
    }
    int find(int a) {
        return (parent[a] == a ? a : (parent[a] = find(parent[a])));
    }
    void merge(int a, int b) {
        if ((a = find(a)) != (b = find(b))) {
            c--;
            if (sz[a] > sz[b]) swap(a, b);
            parent[a] = b;
            sz[b] += sz[a];
        }
    }
};
