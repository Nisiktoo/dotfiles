#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL 
				#define eprintf(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#else 
				#define eprintf(...) 42 
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x),end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int main(int argc, char **argv) {
	startTime = clock();
	/* freopen("input.txt", "r", stdin); */
	/* freopen("output.txt", "w", stdout); */

	int t;
	/* scanf("%d", &t); */
	for (int i = 1; i <= t; i++) {
		/* printf("Case %d: ", i); */

		solve();
		
		/* printf("%lld\n", (ll) solve()); */

		/* if (solve()) { */
		/* 	printf("YES\n"); */
		/* } else { */
		/* 		printf("NO\n"); */
		/* } */
	}

	return 0;
}

