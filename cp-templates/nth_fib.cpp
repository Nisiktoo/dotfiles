/* calculates Fn and Fn+1 */
std::pair<ll, ll> fib (ll n, const ll _m) {
        if (n == 0) {
                return {0, 1};
        }

        auto p = fib(n >> 1, _m);
        ll c = (p.first * (2 * p.second - p.first)) % _m;
        c = (c + _m) % _m;
        ll d = (p.first * p.first + p.second * p.second) % _m;
        d = (d + _m) % _m;
        if (n & 1) {
                return {d, c+d};
        } else {
                return {c, d};
        }
}

