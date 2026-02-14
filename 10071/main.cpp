#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    short v;
    unsigned short t;
    while (std::cin >> v >> t)
        std::cout << v * t * 2 << '\n';
}