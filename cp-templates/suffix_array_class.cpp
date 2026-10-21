struct SuffixArray {
        int n;
        vector<int> p, lcp;
        SuffixArray(string s) {
                p = get_suffix_array(s);
                lcp = get_lcp_array(p, s);
        }


        vector<int> sorted_cyclic_shift(const string &s) {
                int n = s.size();
                const int alphabet = 256;
                vector<int> _p(n), _pn(n), _c(n), _cn(n), _cnt(max(alphabet, n));
                for (int i = 0; i < n; i++) _cnt[s[i]]++;
                for (int i = 1; i < alphabet; i++) _cnt[i] += _cnt[i-1];
                for (int i = 0; i < n; i++) _p[--_cnt[s[i]]] = i;
                _c[_p[0]] = 0;
                int classes = 1;
                for (int i = 1; i < n; i++) {
                        if (s[_p[i]] != s[_p[i-1]]) classes++;
                        _c[_p[i]] = classes - 1;
                }

                for (int h = 0; (1 << h) < n; h++) {
                        for (int i = 0; i < n; i++) {
                                _pn[i] = _p[i] - (1 << h);
                                if (_pn[i] < 0) _pn[i] += n;
                        }
                        fill(_cnt.begin(), _cnt.begin() + classes, 0);
                        for (int i = 0; i < n; i++) _cnt[_c[_pn[i]]]++;
                        for (int i = 1; i < classes; i++) _cnt[i] += _cnt[i-1];
                        for (int i = n - 1; i >= 0; i--) {
                                _p[--_cnt[_c[_pn[i]]]] = _pn[i];
                        }
                        _cn[_p[0]] = 0;
                        classes = 1;
                        for (int i = 1; i < n; i++) {
                                pair<int, int> cur = {_c[_p[i]], _c[(_p[i] + (1 << h)) % n]};
                                pair<int, int> prev = {_c[_p[i-1]], _c[(_p[i-1] + (1 << h)) % n]};
                                if (cur != prev) classes++;
                                _cn[_p[i]] = classes - 1;
                        }
                        _c.swap(_cn);
                }
                return _p;
        }
        vector<int> get_suffix_array(string s) {
                s = s + "$";
                auto _p = sorted_cyclic_shift(s);
                _p.erase(_p.begin());
                return _p;
        }
        vector<int> get_lcp_array(string s) {
                auto _p = get_suffix_array(s);
                return get_lcp_array(_p, s);
        }
        vector<int> get_lcp_array(vector<int> _p, string s) {
                int n = s.size();
                vector<int> rank(n, 0);
                for (int i = 0; i < n; i++) rank[_p[i]] = i;
                int k = 0;
                vector<int> _lcp(n, 0);
                for (int i = 0; i < n; i++) {
                        if (rank[i] == n - 1) {
                                k = 0;
                                continue;
                        }
                        int j = _p[rank[i] + 1];
                        while (i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
                        _lcp[rank[i]] = k;
                        if (k) k--;
                }
                return _lcp;

        }


};
