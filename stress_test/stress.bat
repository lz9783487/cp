@echo off

set compile=g++ -std=c++20 -o
call %compile% a a.cpp
call %compile% b b.cpp
call %compile% gen gen.cpp
FOR /L %%t IN (0, 1, 10000) DO (
	gen > input.txt
	a < input.txt > output_a.txt
	b < input.txt > output_b.txt
	fc output_a.txt output_b.txt> diagnostics.txt || exit /b
	echo %%t
)
