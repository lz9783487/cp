int64_t p[64];

void insert(ull x) {
    for (int i = 63; ~i; --i) {
        if (!(x >> i))  // x 的第 i 位是 0
            continue;
        if (!p[i]) {
            p[i] = x;
            break;
        }
        x ^= p[i];
    }
}