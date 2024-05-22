// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
struct mint {
    ll v; 
    explicit operator ll() const { return v; }
    explicit operator int() const { return v; }
    mint() { v = 0; }
    mint(ll _v) {
        v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0) v += MOD;
    }
    friend bool operator == (const mint &a, const mint &b) { return a.v == b.v; }
    friend bool operator != (const mint &a, const mint &b) { return !(a == b); }
    friend bool operator < (const mint &a, const mint &b) { return a.v < b.v; }
    friend bool operator > (const mint &a, const mint &b) { return a.v > b.v; }
    friend bool operator <= (const mint &a, const mint &b) { return a.v <= b.v; }
    friend bool operator >= (const mint &a, const mint &b) { return a.v >= b.v; }
    friend mint operator + (mint a, const mint &b) { return a += b; }
    friend mint operator - (mint a, const mint &b) { return a -= b; }
    friend mint operator * (mint a, const mint &b) { return a *= b; }
    friend mint operator / (mint a, const mint &b) { return a /= b; }
    mint& operator += (const mint &m) { if ((v += m.v) >= MOD) v -= MOD; return *this; }
    mint& operator -= (const mint &m) { if ((v -= m.v) < 0) v += MOD; return *this; }
    mint& operator *= (const mint &m) { v = v * m.v % MOD; return *this; }
    mint& operator /= (const mint &m) { return (*this) *= inv(m); }
    mint operator - () const { return mint(-v); }
    mint& operator ++ () { return *this += 1; }
    mint& operator -- () { return *this -= 1; }
    mint operator ++ (int) { mint temp; temp.v = v++; return temp; }
    mint operator -- (int) { mint temp; temp.v = v--; return temp; }
    friend mint pow(mint a, ll b) {
        assert(b >= 0);
        mint res = 1;
        while (b) {
            if (b & 1) res *= a;
            a *= a; b >>= 1;
        }
        return res;
    }
    friend mint inv(const mint &a) {
        assert(a.v != 0);
        return pow(a, MOD - 2);
    }
    friend ostream& operator << (ostream &os, const mint &m) {
        os << m.v; return os;
    }
    friend istream& operator >> (istream &is, mint &m) {
        ll x; is >> x; m.v = x; return is;
    }
};
