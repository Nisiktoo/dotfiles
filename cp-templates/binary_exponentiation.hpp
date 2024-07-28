/* Calculates a^b mod m 
 * x^(2n) = x^n * x ^n
 * Algorithm: x^(2n+1) = x * (x^n * x^n);
 */
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  /* uses binary representation of b to calculatea a^b */
  while (b > 0) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
