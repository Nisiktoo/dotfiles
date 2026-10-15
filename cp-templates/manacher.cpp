/* You may only use manacher_even */
vector<int> manacher_odd(string s) {
        int n = s.size();
        int l = 0, r = 1;
        vector<int> a(n);
        for (int i = 1; i < n; i++) {
                if (r > i) {
                        a[i] = min(r - i, a[2 * l - i]);
                }
                while (i + a[i] < n && i - a[i] >= 0 && s[i + a[i]] == s[i - a[i]]) a[i]++;
                if (i + a[i] > r) {
                        l = i;
                        r = i + a[i];
                }
        }
        return a;
}
/* 0th based index
 * b[i].first = maximum number of palindromes where s[i] is the middle character
 * b[i].second = maximum number of even length palindromes where s[i] ans s[i+1] are the middle chars
 */

vector<pair<int, int>> manacher_even(string s) {
        string t = "#";
        for (auto ch : s) {
                t += ch;
                t += "#";
        }
        vector<int> a = manacher_odd(t);
        int n = s.size();
        vector<pair<int, int>> b(n);
        for (int i = 0; i < n; i++) {
                int j = 2 * i + 1;
                b[i].first = a[j] / 2;
                j++;
                b[i].second = a[j] / 2;
        }
        return b;
}
