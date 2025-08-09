You are given a grid with n rows and m columns of non-negative integers and an integer k. Let (i, j) denote the cell in the i-th row from the top and j-th column from the left (1 \le i \le n, 1 \le j \le m). For every cell (i, j), the integer a_{i, j} is written on the cell (i, j).

You are initially at (1, 1) and want to go to (n, m). You may only move down or right. That is, if you are at (i, j), you can only move to (i+1, j) or (i, j+1) (if the corresponding cell exists).

Before you begin moving, you may do the following operation any number of times:

Choose an integer i between 1 and n and cyclically shift row i to the left by 1. Formally, simultaneously set a_{i,j} to a_{i,(j \bmod m) + 1} for all integers j (1 \le j \le m).
Note that you may not do any operation after you start moving.
After moving from (1, 1) to (n, m), let x be the number of operations you have performed before moving, and let y be the sum of the integers written on visited cells (including (1, 1) and (n, m)). Then the cost is defined as kx + y.

Find the minimum cost to move from (1, 1) to (n, m).


Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 \le t \le 10^4). The description of the test cases follows.

The first line contains three space-separated integers n, m, and k (1 \leq n, m \leq 200, 0 \leq k \leq 10^9).

Then, n lines follow. The i-th line contains m space-separated integers, a_{i,1},\,a_{i,2},\,\ldots,\,a_{i,m} (0 \leq a_{i,j} \leq 10^9).

It is guaranteed that the sum of n \cdot m over all test cases does not exceed 5 \cdot 10^4.



Output
For each test case, output a single integer, the minimum cost to move from (1, 1) to (n, m).


Input
5
3 3 100
3 4 9
5 2 4
0 101 101
3 4 1
10 0 0 10
0 0 10 0
10 10 0 10
1 1 3
4
3 2 3
1 2
3 6
5 4
10 10 14
58 49 25 12 89 69 8 49 71 23
45 27 65 59 36 100 73 23 5 84
82 91 54 92 53 15 43 46 11 65
61 69 71 87 67 72 51 42 55 80
1 64 8 54 61 70 47 100 84 50
86 93 43 51 47 35 56 20 33 61
100 59 5 68 15 55 69 8 8 60
33 61 20 79 69 51 23 24 56 28
67 76 3 69 58 79 75 10 65 63
6 64 73 79 17 62 55 53 61 58

Output
113
6
4
13
618