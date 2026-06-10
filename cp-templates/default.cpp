#include <bits/stdc++.h>
#include <cassert>

#ifdef DEBUG
#include <debug.h>
#else
#define dbg(x...)
#endif

using namespace std;
inline int nxt() {
	int x;
	cin >> x;
	return x;
}
inline long long nxtl() {
	long long x;
	cin >> x;
	return x;
}
inline string nxts() {
        string s;
        cin >> s;
        return s;
}
using ll = long long;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using uint = unsigned int;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
typedef std::vector<pii> vpii;
typedef std::vector<pll> vpll;
typedef std::vector<bool> vb;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int> (a, b)(rng)
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define repeat(_x) F0R(_, _x)
#define trav(a, x) for (auto& a : x)
#define nl cout << "\n"
#define ins insert
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define cinv(x) trav(_el, x) cin >> _el
#define coutv(x) trav(_el, x) cout << _el << ' '

template <typename C>
C reversed(const C& c) {
    return C(c.rbegin(), c.rend());
}

template<typename T>
T sqr(T x) {
        return x * x;
}

template <class T>
inline bool chmin(T& a, const T& b) {
        return b < a ? a = b, 1 : 0;
}

template <class T>
inline bool chmax(T& a, const T& b) {
        return a < b ? a = b, 1 : 0;
}

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }
int popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }
int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
int popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
 
template <typename T>
T kth_bit(int k) {
  return T(1) << k;
}
template <typename T>
bool has_kth_bit(T x, int k) {
  return x >> k & 1;
}











void solve() {

}

int main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int _t = 1;
        cin >> _t;
        for (int i = 1; i <= _t; i++) {
                solve();
        }
        return 0;
}
