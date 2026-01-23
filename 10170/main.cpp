#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long long S, D;
    while (std::cin >> S >> D)
    {
        while (D > S)
        {
            D -= S;
            ++S;
        }
        std::cout << S << '\n';
    }
}
