#include <iostream>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned a, b;
    while (std::cin >> a >> b)
    {
        if (!(a || b))
            break;
        std::cout << static_cast<unsigned>(std::floor(std::sqrt(static_cast<float>(b))) 
            - std::ceil(std::sqrt(static_cast<float>(a)))) + 1 << '\n';
    }
}