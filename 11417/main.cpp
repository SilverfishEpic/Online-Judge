#include <iostream>
#include <utility>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto gcd = [](unsigned a, unsigned b)
    {
        while (b) a %= b, std::swap(a, b);
        return a;
    };
    while (true)
    {
        unsigned short N;
        std::cin >> N;
        if (!N) break;
        unsigned G(0);
        for (unsigned i = 1; i < N; ++i)
            for (unsigned j = i + 1; j <= N; ++j)
                G += gcd(i, j);
        std::cout << G << '\n';
    }
}