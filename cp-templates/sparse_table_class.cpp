template<class T> struct SparseTable {
        vector<vector<T>> st;
        SparseTable(int n, T *a) {
                st.push_back(vector<int>(a, a+n));
                for (int i = 1, p = 1; 2 * p <= n; p *= 2, i++) {
                        st.emplace_back(n- (2 * p) + 1);
                        int m = st[i].size();
                        for (int j = 0; j < m; j++) {
                                st[i][j] = Operation(st[i-1][j], st[i-1][j+p]);
                        }
                }


        }
        T Operation(const T &a, const T &b) {
                // define your return function here
                return min(a, b);
        }
                
        SparseTable(const vector<T>& a) : st(1, a) {
                int n = a.size();
                for (int i = 1, p = 1; 2 * p <= n; p *= 2, i++) {
                        st.emplace_back(n- (2 * p) + 1);
                        int m = st[i].size();
                        for (int j = 0; j < m; j++) {
                                st[i][j] = Operation(st[i-1][j], st[i-1][j+p]);
                        }
                }

        }

        // [l, r]
        T query(int l, int r) {
                if (l > r) {
                        // default value
                        return 0;
                }
                int i = __builtin_clz(1) - __builtin_clz(r-l+1);
                return Operation(st[i][l], st[i][r-(1<<i)+1]);
        }

};
