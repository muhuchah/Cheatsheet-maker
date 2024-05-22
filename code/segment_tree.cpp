// 0-base - range[l, r]
class segtree {
public:
    struct node {
        ll sum = 0, mn = 0, cnt = 1;
        template <typename M>
        void apply(const M &v) {
            mn = v; sum = v;
        }
    };
    node unite(const node &a, const node &b) const {
        node res;
        res.sum = a.sum + b.sum;
        res.mn = min(a.mn, b.mn);
        res.cnt = (res.mn == a.mn ? a.cnt : 0) + (res.mn == b.mn ? b.cnt : 0);
        return res;
    }
    inline void pull(int x) {
        tree[x] = unite(tree[2 * x], tree[2 * x + 1]);
    }
    int n; vector<node> tree;
    void build(int x, int l, int r) {
        if (l == r) return;
        int m = (l + r) / 2;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        pull(x);
    }
    template <typename M>
    void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].apply(v[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2 * x, l, m, v);
        build(2 * x + 1, m + 1, r, v);
        pull(x);
    }
    template <typename M>
    void modify(int x, int l, int r, int p, const M &v) {
        if (l == r) {
            tree[x].apply(v);
            return;
        }
        int m = (l + r) / 2;
        if (p <= m) modify(2 * x, l, m, p, v);
        else modify(2 * x + 1, m + 1, r, p, v);
        pull(x);
    }
    node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) return tree[x];
        int m = (l + r) / 2;
        if (m >= rr) return get(2 * x, l, m, ll, rr);
        else if (m < ll) return get(2 * x + 1, m + 1, r, ll, rr);
        return unite(get(2 * x, l, m, ll, rr), get(2 * x + 1, m + 1, r, ll, rr));
    }
    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }
    template <typename M>
    segtree(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(4 * n);
        build(1, 0, n - 1, v);
    }
    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(1, 0, n - 1, ll, rr);
    }
    template <typename M>
    void modify(int p, const M &v) {
        assert(p >= 0 && p <= n - 1);
        modify(1, 0, n - 1, p, v);
    }
};
