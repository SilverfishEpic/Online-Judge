#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long n;
    while (std::cin >> n)
    {
        std::vector<int> block(n);
        for (auto& e : block) std::cin >> e;
        std::sort(block.begin(), block.end());
        
        auto lo = block.begin() + (n - 1) / 2;
        auto hi = std::next(lo, !(n & 1));

        std::cout
            << *lo << ' '
            << std::upper_bound(block.begin(), block.end(), *hi)
            - std::lower_bound(block.begin(), block.end(), *lo) << ' '
            << *hi - *lo + 1 << '\n';
    }
}