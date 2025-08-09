int Exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int d = Exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

void exgcd(int a, int b, int& d, int& x, int& y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}
const int mod = 998244353;
int ni(int a) { // a * x + mod * y == 1
    int d, x, y;
    exgcd(a, mod, d, x, y);
    assert(d == 1);
    return (x % mod + mod) % mod;
}