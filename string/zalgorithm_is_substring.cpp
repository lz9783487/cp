template <typename S>
vector<int> zalgorithm(const S &s) {  // zalgo: [i, ...]与 [0, ...]的前缀匹配长度
    int n = int(s.size());
    if (n == 0) return {};
    vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int &k = z[i];
        k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}
template <typename S>
bool is_substring(S &s, S &t) {  // zalgo: is_substring
    int n = int(s.size()), m = int(t.size());
    S st;
    for (auto &&x : s) st.push_back(x);
    for (auto &&x : t) st.push_back(x);
    auto Z = zalgorithm(st);
    for (int i = n; i < n + m; ++i) {
        if (Z[i] >= n) return true;
    }
    return false;
}