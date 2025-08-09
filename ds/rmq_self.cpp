template <typename T, typename Compare>
struct rmq {
    vector<vector<T>> d;
    rmq(const vector<T> &A) { // [0, n)
        int n = (int) A.size();
        int log_n = 0;
        while ((1 << log_n) <= n) log_n++;
        d = vector<vector<T>>(n, vector<T>(log_n));
        for (int i = 0; i < n; ++i) d[i][0] = A[i];
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                d[i][j] = Compare()(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]) ? d[i][j - 1] : d[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    T query(int l, int r) { // [l, r)
        int k = 0;
        while (1 << (k + 1) <= r - l) k++;
        return Compare()(d[l][k], d[r - (1 << k)][k]) ? d[l][k] : d[r - (1 << k)][k];
    }
};
template <typename T, typename Compare>
struct rmq2 {
    vector<vector<T>> d;
    vector<int> ref;
    rmq2(const vector<T> &A) { // [0, n)
        int n = (int) A.size();
        int log_n = 0;
        while ((1 << log_n) <= n) log_n++;
        d = vector<vector<T>>(n, vector<T>(log_n));
        for (int i = 0; i < n; ++i) {
            d[i][0] = A[i];
        }
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                d[i][j] = Compare()(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]) ? d[i][j - 1] : d[i + (1 << (j - 1))][j - 1];
            }
        }
        ref = vector<int>(n + 1, 0); // pre calc the k
        for (int i = 1; i <= n; ++i) {
            int k = 0;
            while (1 << (k + 1) <= i) k++;
            ref[i] = k;
        }
    }
    T query(int l, int r) { // [l, r), real O(1)
        int k = ref[r - l];
        return Compare()(d[l][k], d[r - (1 << k)][k]) ? d[l][k] : d[r - (1 << k)][k];
    }
};
void test() {
	vector<int> data = {1, 5, 2, 4, 3};
	rmq2<int, less<int>> rmqMin(data); // 使用默认的 std::less<>
	rmq2<int, decltype([](const int& a, const int& b) { return a > b; })> rmqMax(data); // 使用自定义比较函数
	rmq2<int, greater<int>> rmqMax1(data);
	int minVal = rmqMin.query(1, 3); // 查询最小值
	int maxVal = rmqMax.query(1, 3); // 查询最大值
	int maxVal1 = rmqMax1.query(1, 3); // 查询最大值
	cout << minVal << ' ' << maxVal << ' ' << maxVal1 << endl;
}
