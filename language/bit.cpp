/*
c++20
bit_cast
byteswap
has_single_bit
bit_ceil
bit_floor
bit_width
rotl
rotr
countl_zero
countl_one
countr_zero
countr_one
popcount
*/
int topbit(uint64_t x) {
    return (x == 0 ? -1 : 63 - __builtin_clzll(x)); 
}
int lowbit(uint64_t x) {
    return (x == 0 ? -1 : __builtin_ctzll(x));
}
int popcnt(uint64_t x) {
    return __builtin_popcountll(x);
}
bool have_bit(uint64_t x, int p) {
    return x >> p & 1;
}
bool no_bit(uint64_t x, int p) {
    return !hasbit(x, p);
}
