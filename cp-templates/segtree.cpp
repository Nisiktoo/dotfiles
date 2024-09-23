const int N = 200100;
ll T[N*4];
ll Lazy[N*4];
/* build segtree for the array _ar 
 * _Tree is the array to store segtree
 * v - current vertex of the segtree
 * tl & tr - range of the vertex v
 * v*2 and v*2+1 are the children of v
 * make sure to replace OP() with appropriate function
 */
void build(ll _Tree[], int _ar[], int v, int tl, int tr) {
        if (tl == tr) {
                T[v] = _ar[tl];
        } else {
                int tm = (tl + tr) / 2;
                build(_Tree, _ar, v*2, tl, tm);
                build(_Tree, _ar, v*2+1, tm+1, tr);
                _Tree[v] = std::max(_Tree[v*2], T[v*2+1]);
        }
}

// _Tree is the segtree array
void push(ll _Tree[], int v) {  
        // Here use the appropriate operator (+, -, /, or other function)
        // pass the pending values to left child
        _Tree[v*2] += Lazy[v]; 
        Lazy[v*2] += Lazy[v];
        // pass the pending values to right child
        _Tree[v*2+1] += Lazy[v];
        Lazy[v*2+1] += Lazy[v];
        Lazy[v] = 0;
}

/* _Tree - the segtree
 * v - current node
 * tl and tr - range of the current node
 * l and r - range of the addened to be added
 */
void update(ll _Tree[], int v, int tl, int tr, int l, int r, int addened) {
        if (l > r) return;
        if (l == tl && tr == r) {
                _Tree += addened;
                Lazy[v] += addened;
        } else {
                push(_Tree, v);
                int tm = (tl + tr) / 2;
                update(_Tree, v*2, tl, tm, l, std::min(tm, r), addened);
                update(_Tree, v*2+1, tm+1, tr, std::max(l, tm+1), r, addened);
                _Tree[v] = std::max(_Tree[v*2], _Tree[v*2+1]); // use appropriate function
        }
}

ll seg_query(ll _Tree[], int v, int tl, int tr, int l, int r) {
        if (l > v) {
                return -1e18; // return a dummy value which doesn't effect the result
        } 
        if (l == tl && tr == r) {
                return _Tree[v];
        }
        push(_Tree, v);
        int tm = (tl + tr) / 2;
        return std::max(seg_query(_Tree, v*2, tl, tm, l, std::min(r, tm)),
                        seg_query(_Tree, v*2+1, tm+1, tr, std::max(l, tm+1), r) ); // use appropriate function
}
