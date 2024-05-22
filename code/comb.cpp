mint fact[N], fact_inv[N];
void init_fact(int n) {
    fact[0] = 1;
    for (int i = 1; i < n; i++)
        fact[i] = fact[i - 1] * i;
    fact_inv[n - 1] = inv(fact[n - 1]);
    for (int i = n - 2; i >= 0; i--)
        fact_inv[i] = fact_inv[i + 1] * (i + 1);
}
mint comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * fact_inv[k] * fact_inv[n - k];
}
