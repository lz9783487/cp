
#define N 1000005
#define g 3//模数的原根
#define mod 998244353//通常情况下的模数
int pow(int x, int y) {
    ll z = 1ll * x, ans = 1ll;
    for (; y; y >>= 1, z = z * z % mod) {
        if (y & 1) {
            ans = ans * z % mod;
        }
    }
    return (int) ans % mod;
}
int rev[N];
inline void ntt(int a[], int len, int inv) {
    int bit = 0;
    while ((1 << bit) < len)++bit;
    fk (i, 0, len) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int mid = 1; mid < len; mid <<= 1) {
        int tmp = pow(g, (mod - 1) / (mid * 2));
        if (inv == -1) {
            tmp = pow(tmp, mod - 2);
        }
        for (int i = 0; i < len; i += mid << 1) {
            int omega = 1;
            for (ll j = 0; j < mid; ++j, omega = 1ll * omega * tmp % mod) {
                int x = a[i + j];
                int y = omega * 1ll * a[i + j + mid] % mod;
                a[i + j] = (x + y) % mod;
                a[i + j + mid] = (x - y + mod) % mod;
            }
        }
    }
    if (inv == -1) {
        int ni = pow(len, mod - 2);
        for (int i = 0; i < len; ++i) {
            a[i] = a[i] * 1ll * ni % mod;
        }
    }
}
const int n = 4;
int main() {
    int a[] = {7, 9, 0, 0};
    int b[] = {9, 3, 0, 0};
    int c[n];
    ntt(a, n, 1);
    ntt(b, n, 1);
    fk (i, 0, n) {
        c[i] = a[i] * 1ll * b[i] % mod;
    }
    ntt(c, n, -1);
    debug(vi(c, c + 4));
}