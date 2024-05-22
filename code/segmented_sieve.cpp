bitset<N> is_prime; 
// is_prime._Find_next(p); is_prime._Find_first();
void segmented_sieve(int n) {
    int sq = sqrt(n) + 1;
    is_prime[0] = is_prime[1] = 1;
    vector<array<int, 2>> small_primes;
    for (int i = 2; i <= sq; i++)
        if (!is_prime[i]) {
            small_primes.push_back({i, i * i});
            for (int j = i * i; j <= sq; j += i)
                is_prime[j] = 1;
        }
    const int block_size = 1 << 18;
    for (int from = 0; from < n; from += block_size) {
        int to = min(from + block_size - 1, n - 1);
        for (array<int, 2> &p : small_primes)
            for (; p[1] <= to; p[1] += p[0])
                is_prime[p[1]] = 1;
    }
    is_prime.flip();
}
