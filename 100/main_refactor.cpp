#include <algorithm>  // std::max, std::minmax
#include <cstdint>    // std::uint_fast32_t
#include <iostream>   // std::cin, std::cout

using u32 = std::uint_fast32_t;

int cycle_length(u32 n) {
    int len = 1;
    while (n != 1)
    {
        n = n & 1u ? 3 * n + 1 : n >>= 1;
        ++len;
    }
    return len;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    u32 i = 0, j = 0;
    while (std::cin >> i >> j) {
        const auto [lo, hi] = std::minmax(i, j);

        int best = 0;
        for (u32 n = lo; n <= hi; ++n)
            best = std::max(best, cycle_length(n));

        std::cout << i << ' ' << j << ' ' << best << '\n';
    }
}
