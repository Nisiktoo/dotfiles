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
