#include <iostream>
#include <utility>
#include <array>
#include <iomanip>

using Point = std::pair<double, double>; // if using float will WA!!!!
using Edge = std::array<Point, 2>;

std::istream& operator >>(std::istream& is, Point& point)
{
    return is >> point.first >> point.second;
}

std::istream& operator >>(std::istream& is, Edge& edge)
{
    for (auto& p : edge)
        is >> p;
    return is;
}

std::istream& operator >>(std::istream& is, std::array<Edge, 2>& edges)
{
    for (auto& p : edges)
        is >> p;
    return is;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<Edge, 2> edges;
    while (std::cin >> edges)
    {
        bool branch_ctl = 0;
        while (edges[0][0] != edges[1][0])
        {
            if (branch_ctl)
                std::swap(edges[0][0], edges[0][1]);
            else std::swap(edges[1][0], edges[1][1]);
            branch_ctl = !branch_ctl;
        }
        std::cout << std::fixed << std::setprecision(3)
            << edges[0][1].first + edges[1][1].first - edges[0][0].first << ' '
            << edges[0][1].second + edges[1][1].second - edges[0][0].second << '\n';
    }
}