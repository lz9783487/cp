#ifndef LZ_DEBUG_H
#define LZ_DEBUG_H

#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

std::string toString(int);
std::string toString(unsigned int);
std::string toString(short);
std::string toString(unsigned short);
std::string toString(long long);
std::string toString(unsigned long long);
std::string toString(float);
std::string toString(long);
std::string toString(double);
std::string toString(long double);
std::string toString(char);
std::string toString(char *);
std::string toString(char const *);
std::string toString(bool);
std::string toString(std::string);
std::string toString(__uint128_t);
std::string toString(__int128_t);
template <typename T, size_t N>
std::string toString(std::array<T, N>);
template <typename T, size_t N>
std::string toString(T (&arr)[N]);
template <size_t N>
std::string toString(std::bitset<N>);
template <typename A>
std::string toString(std::tuple<A>);
template <typename A, typename B>
std::string toString(std::tuple<A, B>);
template <typename A, typename B, typename C>
std::string toString(std::tuple<A, B, C>);
template <typename A, typename B, typename C, typename D>
std::string toString(std::tuple<A, B, C, D>);
template <typename A, typename B, typename C, typename D, typename E>
std::string toString(std::tuple<A, B, C, D, E>);
template <typename A, typename B, typename C, typename D, typename E, typename F>
std::string toString(std::tuple<A, B, C, D, E, F>);
template <typename A, typename B>
std::string toString(std::pair<A, B>);
template <typename T, typename Container, typename Compare>
std::string toString(std::priority_queue<T, Container, Compare>);
template <typename T>
std::string toString(std::stack<T>);
template <typename T>
std::string toString(std::queue<T>);
template <typename T>
std::string toString(T);

std::string toString(int x) {
	return std::to_string(x);
}
std::string toString(unsigned int x) {
	return std::to_string(x);
}
std::string toString(short x) {
	return std::to_string(x);
}
std::string toString(unsigned short x) {
	return std::to_string(x);
}
std::string toString(long long x) {
	return std::to_string(x);
}
std::string toString(unsigned long long x) {
	return std::to_string(x);
}
std::string toString(float x) {
	return std::to_string(x);
}
std::string toString(long x) {
	return std::to_string(x);
}
std::string toString(double x) {
	return std::to_string(x);
}
std::string toString(long double x) {
	return std::to_string(x);
}
std::string toString(char x) {
	return "'" + std::string() + x + "'";
}
std::string toString(char *s) {
	return std::string(s);
}
std::string toString(char const *s) { return std::string(s); }
std::string toString(bool x) {
	if (x)
		return "true";
	else
		return "false";
}
std::string toString(std::string s) {
	return "\"" + s + "\"";
}

std::string toString(__uint128_t x) {
	if (x == 0) {
		return "0";
	} else {
		std::string re;
		while (x) {
			re += '0' + x % 10;
			x /= 10;
		}
		std::reverse(re.begin(), re.end());
		return re;
	}
}

std::string toString(__int128_t x) {
	if (x == 0)
		return "0";
	else {
		std::string z = x > 0 ? "" : "-";
		__uint128_t val = x > 0 ? x : -x;
		return z + toString(val);
	}
}

template <typename T, size_t N>
std::string toString(std::array<T, N> arr) {
	return toString(std::vector<T>(arr.begin(), arr.end()));
}

template <typename T, size_t N>
std::string toString(T (&arr)[N]) {
	return toString(std::vector<T>(arr, arr + N));
}

template <size_t N>
std::string toString(std::bitset<N> x) {
	return x.to_string();
}

template <typename A>
std::string toString(std::tuple<A> x) {
	return "(" + toString(std::get<0>(x)) + ")";
}

template <typename A, typename B>
std::string toString(std::tuple<A, B> x) {
	return "(" + toString(std::get<0>(x)) + ", " + toString(std::get<1>(x)) + ")";
}

template <typename A, typename B, typename C>
std::string toString(std::tuple<A, B, C> x) {
	return "(" + toString(std::get<0>(x)) + ", " + toString(std::get<1>(x)) + ", " + toString(std::get<2>(x)) + ")";
}

template <typename A, typename B, typename C, typename D>
std::string toString(std::tuple<A, B, C, D> x) {
	return "(" + toString(std::get<0>(x)) + ", " + toString(std::get<1>(x)) + ", " + toString(std::get<2>(x)) + ", " + toString(std::get<3>(x)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
std::string toString(std::tuple<A, B, C, D, E> x) {
	return "(" + toString(std::get<0>(x)) + ", " + toString(std::get<1>(x)) + ", " + toString(std::get<2>(x)) + ", " + toString(std::get<3>(x)) + ", " + toString(std::get<4>(x)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E, typename F>
std::string toString(std::tuple<A, B, C, D, E, F> x) {
	return "(" + toString(std::get<0>(x)) + ", " + toString(std::get<1>(x)) + ", " + toString(std::get<2>(x)) + ", " + toString(std::get<3>(x)) + ", " + toString(std::get<4>(x)) + ", " + toString(std::get<5>(x)) + ")";
}

template <typename A, typename B>
std::string toString(std::pair<A, B> x) {
	return "(" + toString(x.first) + ", " + toString(x.second) + ")";
}

template <typename T, typename Container = std::vector<T>, typename Compare = std::less<typename Container::value_type>>
std::string toString(std::priority_queue<T, Container, Compare> pq) {
	Container c;
	while (!pq.empty()) {
		c.push_back(pq.top());
		pq.pop();
	}
	return toString(c);
}

template <typename T>
std::string toString(std::stack<T> x) {
	std::vector<T> v;
	while (!x.empty()) {
		v.push_back(x.top());
		x.pop();
	}
	return toString(v);
}

template <typename T>
std::string toString(std::queue<T> x) {
	std::vector<T> v;
	while (!x.empty()) {
		v.push_back(x.front());
		x.pop();
	}
	return toString(v);
}

template <typename T>
std::string toString(T v) {
	bool first = true;
	std::string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += toString(x);
	}
	res += "}";
	return res;
}

void Debug();

template <typename Head, typename... Tail>
void Debug(Head, Tail...);

#define _dbg_output std::cerr
#define _dbg_flush std::cout.flush(); std::cerr.flush()

void Debug() {
    _dbg_flush;
	_dbg_output << std::endl;
    _dbg_flush;
}

template <typename Head, typename... Tail>
void Debug(Head H, Tail... T) {
    _dbg_flush;
	_dbg_output << " " << toString(H);
    _dbg_flush;
    _dbg_flush;
	Debug(T...);
    _dbg_flush;
}

// 调试数组时要使用 debug(toString(arr))
#define debug(...) _dbg_output << "[" << __LINE__ << ", " <<  #__VA_ARGS__ << "]:", Debug(__VA_ARGS__)

#endif  // LZ_DEBUG_H
