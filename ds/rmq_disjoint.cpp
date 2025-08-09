/*
    mat[0] 就是原数组
    mat[p] 是逐长度为2**p的段进行分割，每段都从中心开始向左/右求后/前缀和
    例如p = 1, 2**p = 2
    分段为[0, 4), [4, 8), [8, 16), [16, 32), [32, 64)
    每段的中心为2, 2 + 4, 2 + 4 + 4, ...

    查询时, 如果
    l = 1101​[0​]01
    r = 1101​[1​]10
    l和r在最大的4层中位于相同的段中
    在mat[2]中，二者位于某一段中的中心的两侧
*/
template <typename T, typename F>
class DisjointSparseTable {
   public:
    int n;
    vector<vector<T>> mat;
    F func;

    DisjointSparseTable(const vector<T>& a, const F& f) : n(int(a.size())), func(f) {
        mat.push_back(a);
        for (int p = 1; (1 << p) < n; p++) {
            mat.emplace_back(n);
            for (int mid = 1 << p; mid < n; mid += 1 << (p + 1)) {
                mat[p][mid - 1] = a[mid - 1];
                for (int j = mid - 2; j >= mid - (1 << p); j--) {
                    mat[p][j] = func(a[j], mat[p][j + 1]);
                }
                mat[p][mid] = a[mid];
                for (int j = mid + 1; j < min(n, mid + (1 << p)); j++) {
                    mat[p][j] = func(mat[p][j - 1], a[j]);
                }
            }
        }
    }

    T Query(int l, int r) const {
        assert(0 <= l && l < r && r <= n);
        if (r - l == 1) {
            return mat[0][l];
        }
        // bit_width = topbit所在位置，等价于32(64) - __builtin_clz(ll)
        int p = bit_width(unsigned(l ^ (r - 1))) - 1;
        return func(mat[p][l], mat[p][r - 1]);
    }
};

// DisjointSparseTable<int, greater<int>> ra(a, greater<int>()); // 错误
// DisjointSparseTable ra(a, std::function(std::gcd<int, int>));
// DisjointSparseTable ra(a, [&](int x, int y) { return min(x, y); });