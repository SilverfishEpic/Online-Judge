#include <iostream>
#include <utility>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned short n;
    std::cin >> n;
    auto calc = [](std::pair<unsigned, unsigned> point) {
        unsigned const h = point.first + point.second;
        return (1 + h) * h / 2 + point.first;
    };
    for (unsigned short i = 0; i++ != n;)
    {
        std::pair<unsigned, unsigned> src, dest;
        std::cin >> src.first >> src.second >> dest.first >> dest.second;
        std::cout << "Case " << i << ": " << calc(dest) - calc(src) << '\n';
    }
}