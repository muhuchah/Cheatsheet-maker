// range_update + point_query
// 0-base _ range[l, r]
struct fenwick_tree { 
    int n; vector<ll> f;
    fenwick_tree(int _n) : n(_n)
        f.resize(n, 0);
    void modify(int s, ll val) {
        if (s < 0) return;
        for (int i = s; i < n; i = i | (i + 1))
            f[i] += val;
    }
    void modify(int l, int r, ll val) {
        modify(l, val);
        modify(r + 1, -val);
    }
    ll get(int p) {
        ll res = 0;
        for (int i = p; i >= 0; i = (i & (i + 1)) - 1)
            res += f[i];
        return res;
    }
};
