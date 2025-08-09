const int N = (int) 1e7 + 5;
int cntp = 0;
vector<int> pri, pri_ord(N, 0), min_factor(N, 0);
bool not_prime[N];
void init() {
    for (int i = 2; i < N; ++i) {
        if (!not_prime[i]) {
            pri.push_back(i);
            pri_ord[i] = cntp++;
            min_factor[i] = i;
        }
        for (int pri_j : pri) {
            if (i * pri_j >= N) break;
            not_prime[i * pri_j] = true;
            min_factor[i * pri_j] = pri_j;
            if (i % pri_j == 0) {
                break;
            }
        }
    }
}
map<long long, int> decomp(int x) {
    map<long long, int> mp;
    while (x != 1) {
        int mf = min_factor[x];
        mp[mf]++;
        x /= mf;
    }
    return mp;
}
map<long long, int> decomp(long long x) {
    map<long long, int> mp;
    for (long long i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            mp[i]++;
            x /= i;
        }
    }
    if (x > 1) {
        mp[x]++;
    }
    return mp;
}
int main() {
    init();
    for (int i = 1; i < 10000; ++i) {
        assert(decomp(i) == decomp((long long) i));
    }
    cout << "OK" << '\n';
    return 0;
}