#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned n;
    std::cin >> n;
    while (n--)
    {
        unsigned s, d;
        std::cin >> s >> d;
        if (d > s || (s + d) % 2)
        {
            std::cout << "impossible\n";
            continue;
        }
        std::cout << (s + d) / 2 << ' ' << (s - d) / 2 << '\n';
    }
}
