struct FenwickTree {
	std::vector<ll> bit; // binary indexed tree
	int n;

	FenwickTree(int n) {
		this->n = n;
		bit.assign(n, 0);
	}
	FenwickTree(std::vector<int> const &a) : FenwickTree(a.size()) {
		for (int i = 0; i < n; i++) {
			bit[i] += a[i];
			int r = i | (i + 1);
			if (r < n) bit[r] += bit[i];
		}
	}
	ll sum(int r) {
		ll ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) {
			ret += bit[r];
		}
		return ret;
	}

	void add(int idx, int delta) {
		for (; idx < n; idx = idx | (idx + 1)) {
			bit[idx] += delta;
		}
	}
};
