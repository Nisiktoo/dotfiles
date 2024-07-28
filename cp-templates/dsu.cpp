struct dsu {
  private:
  std::vector<int> _parent, Size;
  public:
    dsu() {
    }
    dsu(int _sz) {
      _parent.resize(_sz+1);
      Size.resize(_sz+1);
      for (int i = 0; i <= _sz; i++) {
        _parent[i] = i;
        Size[i] = 1;
      }
    }
    void union_set(int _a, int _b) {
      _a = find_set(_a);
      _b = find_set(_b);
      if (_a != _b) {
        if (Size[_a] < Size[_b]) {
          std::swap(_a, _b);
        }
        _parent[_b] = _a;
        Size[_a] += Size[_b];
      }
    }
    int find_set(int _v) {
      if (_v == _parent[_v]) {
        return _v;
      }
      return _parent[_v] = find_set(_parent[_v]);
    }
};
