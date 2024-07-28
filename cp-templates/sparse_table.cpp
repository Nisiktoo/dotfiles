const int MAXN = 200100, K = 25; /* MAXN = max array length, K >= lg(MAXN) */
int st[K+1][MAXN]; /* st[i][j] storens answer of the range [j, j + 2^i - 1] */
int log2_floor(unsigned long long i) {
	return i ? __builtin_clzll(1) - __builtin_clzll(i) : 1;
}

/* usage :
 * i = log2_floor(r-l+1)
 * ans = f(st[i][l], st[i][r-(1<<i) + 1)
*/

void precompute_sparse_table() {
	std::copy(array.begin(), array.end(), st[0]);

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j + (1 << i) <= MAXN; j++) {
                        /* define your function f() */
			st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}
}
