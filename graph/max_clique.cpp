struct MC {
    int x[105][105];
    int z[105][105];
    int best;
    int bests[105];
    int n;
    int dfs(int ceng, int m) { // ceng shi zui datuan, m shi ke kuo zhan dian
        if (m == 0) {
            if (ceng > best) {
                best = ceng;
                return 1;
            }
            return 0;
        }
        for (int i = 0; i < m; ++i) {
            if (m - i + ceng <= best) { // sheng yu dian jian zhi
                return 0;
            }
            int u = z[ceng][i];
            if (bests[u] + ceng <= best) { // xia jie jian zhi
                return 0;
            }
            int ji = 0;
            for (int j = i + 1; j < m; ++j) {
                if (x[u][z[ceng][j]]) {
                    z[ceng + 1][ji++] = z[ceng][j];
                }
            }
            if (dfs(ceng + 1, ji)) {
                return 1;
            }
        }
    }
    int max_clique() {
        best = 0;
        memset(bests, 0, sizeof(bests));
        for (int i = n - 1; i >= 0; --i) {
            int ji = 0;
            for (int j = i + 1; j < n; ++j) {
                if (x[i][j]) {
                    z[1][ji++] = j;
                }
            }
            dfs(1, ji);
            bests[i] = best;
        }
        return best;
    }
} mc;