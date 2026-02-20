#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned short test_cases;
    std::cin >> test_cases;
    for (unsigned short x = 0; x++ != test_cases;)
    {
        std::cout << "Case " << x << ":\n";
        std::vector<unsigned short> costs(36);
        for (auto& cost : costs) std::cin >> cost;
        unsigned queries;
        std::cin >> queries;
        while (queries--)
        {
            unsigned long query;
            std::cin >> query;
            std::vector<unsigned> query_costs;
            for (unsigned base = 2; base != 37; ++base)
            {
                query_costs.push_back(0);
                decltype(query) d = query;
                while (d)
                {
                    query_costs.back() += costs[d % base];
                    d /= base;
                }
            }
            std::cout << "Cheapest base(s) for number " << query << ": ";
            auto const& list_begin = query_costs.cbegin();
            auto const& list_end = query_costs.cend();
            auto const& first_least = std::min_element(list_begin, list_end);
            std::cout << 2 + std::distance(list_begin, first_least);
            for (auto iter = std::find(std::next(first_least), list_end, *first_least);
                iter != list_end;
                iter = std::find(std::next(iter), list_end, *first_least))
                std::cout << ' ' << 2 + std::distance(list_begin, iter);
            std::cout << '\n';
        }
        if (x != test_cases) std::cout << '\n';
    }
}