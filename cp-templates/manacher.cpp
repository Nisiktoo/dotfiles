/* source : https://cp-algorithms.com/string/manacher.html */
/* Manacher's Algorithm - Finding all sub-palindromes in O(N) */
/* manacher_odd returns a vector d.
 * d[i] = number of non-empty odd-length palindromes centered at this position
 * 2*d[i] - 1 is the length of the largest palindrome centered at i
 * Time Complexity : O(n)
*/
std::vector<int> manacher_odd(std::string pstr) {
        int pstr_len = pstr.size();
        pstr = "$" + pstr + "^";
        /* boundaries of the rightmost found palidrome
         * pstr[l+1,..,r-1] is the palidrome.
         */
        int l = 1, r = 1;         
        std::vector<int> p(pstr_len+2);
        for (int i = 1; i <= pstr_len; i++) {
                p[i] = std::max(0, std::min(r-i, p[l+(r-i)]));
                while (pstr[i - p[i]] == pstr[i+p[i]]) {
                        p[i]++;
                }
                if (i + p[i] > r) {
                        l = i - p[i], r = i + p[i];
                }
        }
        return std::vector<int>(std::begin(p)+1, std::end(p) - 1);
}
/* 
 * D_odd[i] = number of odd length palindromes centered at str[i]
 * D_odd[i] = d[2i+1]/2;
 * Longest palidrome length centered at i = 2 * D_odd[i] - 1
 * D_even[i] = number of even length palindromes centered at str[i]
 * D_even[i] = (d[2i] - 1) / 2
 * Longest even palidrome length centered at i = 2 * D_even[i];
*/
std::vector<int> manacher(const char *str) {
        std::string tstr;
        for (int i = 0; str[i]; i++) {
                tstr += std::string("#") + str[i];
        }

        auto res = manacher_odd(tstr + "#");
        auto d =  std::vector<int>(std::begin(res)+1, std::end(res)-1);
        return d;
}
