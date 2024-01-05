const int N = 1e7 + 10; // find prime numbers upto N
std::vector<int> mpf (N); // mpf[i] = minimum prime factor of i
std::vector<int> primes; // stores primes upto N

/* Linear Sieve that supports prime factorization */ 
void linear_sieve() {
	for (int i = 2; i <= N; i++) {
		if (mpf[i] == 0) {
			mpf[i] = i;
			primes.push_back(i);
		}
		for (int j = 0; (long long) i * primes[j] <= N; j++) {
			mpf[i * primes[j]] = primes[j];
			if (primes[j] == mpf[i]) {
				break;
			}
		}
	}
}
