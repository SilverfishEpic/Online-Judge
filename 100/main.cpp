#include <iostream>
#include <utility>
#include <cstdint>

int cycle_length(std::uint_fast32_t n)
{
    int count = 1;
    while (n != 1)
    {
        n = n % 2 ? 3 * n + 1 : n / 2;
        ++count;
    }
    return count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::uint_fast32_t i, j;
    while (std::cin >> i >> j)
    {
        auto x = i, y = j;
        if (y < x) std::swap(x, y);
        int max = 0;
        for (auto n = x; n <= y; ++n)
        {
            int cycle = cycle_length(n);
            if (cycle > max) max = cycle;
        }
        std::cout << i << ' ' << j << ' ' << max << '\n';
    }
}