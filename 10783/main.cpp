#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, a, b;
    std::cin >> t;
    for (auto i = 1; i <= t; ++i)
    {
        std::cin >> a >> b;
        if (!(a % 2)) ++a;
        if (!(b % 2)) --b;
        std::cout << "Case " << i << ": " << static_cast<int>((b + a) * (0.25 * (b - a) + 0.5)) << '\n';
    }
}