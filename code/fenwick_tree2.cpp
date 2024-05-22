// range_update + range_query
// 0-base _ range[l, r]
struct fenwick_tree {
    int n; vector<ll> f1, f2;
    fenwick_tree(int _n) : n(_n) {
        f1.resize(n, 0);
        f2.resize(n, 0);
    }
    void modify(int s, ll mul, ll add) {
        for (int i = s; i < n; i = i | (i + 1)) {
            f1[i] += mul;
            f2[i] += add;
        }
    }
    ll get(int p) {
        ll mul = 0, add = 0;
        for (int i = p; i >= 0; i = (i & (i + 1)) - 1) {
            mul += f1[i];
            add += f2[i];
        }
        return (mul * p + add);
    }
    void modify(int l, int r, ll x) {
        modify(l, x, -x * (l - 1));
        modify(r, -x, x * r);
    }
    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};
