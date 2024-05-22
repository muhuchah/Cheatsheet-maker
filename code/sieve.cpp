vector<int> primes, min_factor;
void sieve(int n) {
    min_factor.resize(n, 0);
    min_factor[1] = 1;
    for (int i = 2; i < n; i++) {
        if (min_factor[i] == 0) {
            primes.push_back(i);
            min_factor[i] = i;
        }
        for (int j = 0; j < (int)primes.size() && 
        i * primes[j] < n && primes[j] <= min_factor[i]; j++)
            min_factor[i * primes[j]] = primes[j];
    }
}
