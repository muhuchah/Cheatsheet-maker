using u128 = __uint128_t;
ll binpow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1) 
            res = (u128)res * a % m;
        a = (u128)a * a % m;
        b >>= 1;
    }
    return res;
}
bool check_composite(ll n, ll a, ll d, int s) {
    ll x = binpow(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
}
bool miller_rabin(ll n) { // returns true if n is prime
    if (n < 2) return false;
    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1; r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (check_composite(n, a, d, r)) return false;
    }
    return true;
}
