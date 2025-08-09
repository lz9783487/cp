class RanGenerator {
private:
    std::mt19937_64 rng;
public:
    RanGenerator(): rng(random_device{}()) {}
    template <typename T>
    T mtrand(T n) { // [0, n)
        std::uniform_int_distribution<T> dist(0, n - 1);
        return dist(rng);
    }
    template <typename T>
    T mtrand(T a, T b) { // [a, b)
        std::uniform_int_distribution<T> dist(a, b - 1);
        return dist(rng);
    }
    double mtrand(double a, double b) { // [a, b]
        std::uniform_real_distribution<double> dist(a, b);
        return dist(rng);
    }
    long double mtrand(long double a, long double b) { // [a, b]
        std::uniform_real_distribution<long double> dist(a, b);
        return dist(rng);
    }
};
// std::chrono::steady_clock::now().time_since_epoch().count()
// uniform_int_distribution的构造依赖随机数生成器gen，gen.min()和gen.max()提供其范围
// uniform_int_distribution将[gen.min(), gen.max()]映射到指定范围