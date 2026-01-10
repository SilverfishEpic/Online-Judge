/*
WA
1) UVa 100 的輸入可能是 i j 其中 i > j（例如 10 1），
但題目要求你仍要輸出「原本的 i j」並計算區間 [min(i,j), max(i,j)] 的最大 cycle length。

2) 使用 recursion 而非 iteration
*/

#include <iostream>

unsigned long three_n_plus_one(unsigned long n)
{
    if (n == 1) return 1;
    else if (n % 2) return 1 + three_n_plus_one(3 * n + 1);
    else return 1 + three_n_plus_one(n / 2);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long i, j;
    while (std::cin >> i >> j)
    {
        int max = 0;
        for (auto n = i; n <= j; ++n)
        {
            int cycle = three_n_plus_one(n);
            if (cycle > max) max = cycle;
        }
        std::cout << i << ' ' << j << ' ' << max << '\n';
    }
}