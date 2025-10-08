struct Dsu {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ x >> 30) * 0xbf58476d1ce4e5b9;
    x = (x ^ x >> 27) * 0x94d049bb133111eb;
    return x ^ x >> 31;
  }
  int n;
  vector<int> fa, sz;
  vector<u64> element, comp_xor;
  u64 total = 0;
  static constexpr u64 salt1 = 0x9e3779b97f4a7c15ULL, salt2 = 0xa0761d6478bd642FULL;
  static constexpr u64 salt_base = 0x243f6a8885a308d3ULL;
  struct Op {
    int b, fa_b, sz_a;
    u64 xor_a, total_old;
  };
  vector<Op> stk;
  explicit Dsu(int n_)
      : n(n_), fa(n), sz(n, 1), element(n), comp_xor(n) {
    iota(fa.begin(), fa.end(), 0);
    for (int i = 0; i < n; i++) {
      element[i] = splitmix64((u64) i ^ salt_base);
      comp_xor[i] = element[i];
    }
    for (int i = 0; i < n; i++) {
      total ^= set_hash(i);
    }
  }
  int find(int x) const {
    while (fa[x] != x) x = fa[x];
    return x;
  }
  u64 set_hash(int i) const {
    return splitmix64(comp_xor[i] + salt1) ^ splitmix64((u64) sz[i] + salt2);
  }
  bool unite(int x, int y) {
    int a = find(x), b = find(y);
    if (a == b) {
      stk.push_back({-1, 0, 0, 0, 0});
      return false;
    }
    if (sz[a] < sz[b]) swap(a, b);
    stk.push_back({b, fa[b], sz[a], comp_xor[a], total});
    total ^= set_hash(a) ^ set_hash(b);
    fa[b] = a;
    sz[a] += sz[b];
    comp_xor[a] ^= comp_xor[b];
    total ^= set_hash(a);
    return true;
  }
  void rollback() {
    Op t = stk.back();
    stk.pop_back();
    if (t.b == -1) {
      return;
    }
    int a = fa[t.b];
    total = t.total_old;
    comp_xor[a] = t.xor_a;
    sz[a] = t.sz_a;
    fa[t.b] = t.fa_b;
  }
  u64 set_hash_of(int x) {
    return set_hash(find(x));
  }
  u64 all_hash() const {
    return total;
  }
};