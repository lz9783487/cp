@echo off
@REM g++ -std=c++20 -o a a.cpp
@REM g++ -std=c++20 -o b b.cpp
a < input.txt > output_a.txt
b < input.txt > output_b.txt
