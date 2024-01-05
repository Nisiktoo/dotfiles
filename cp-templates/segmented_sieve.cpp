std::vector<int> primes; // store primes

/* Find and count primes up to n */
int count_primes(int n) {
	const int S = 10000; /* segment size */ 
	int nsqrt = std::sqrt(n);
	std::vector<int> pr;
	std::vector<char> is_prime(nsqrt+2, true);
	for (int i = 2; i <= nsqrt; i++) {
		if (is_prime[i]) {
			pr.push_back(i);
			/* primes.push_back(i); */
			for (int j = i * i; j <= nsqrt; j += i) {
				is_prime[j] = false;
			}
		}
	}
	int result = 0;
	std::vector<char> block(S);
	for (int k = 0; k * S <= n; k++) {
		fill(block.begin(), block.end(), true);
		int start = k * S;
		for (int p : pr) {
			int start_idx = (start + p - 1) / p;
			int j = std::max(start_idx, p) * p - start;
			for (; j < S; j += p) {
				block[j] = false;
			}
		}
		if (k == 0) block[0] = block[1] = false;
		for (int i = 0; i < S && start + i <= n; i++) {
			if (block[i]) {
				result++;
				primes.push_back(start+i);
			}
		}
	}
	return result;
}
