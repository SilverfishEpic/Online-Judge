#include <iostream>
#include <string>
#include <map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    short n;
    std::map<std::string, int> list;
    std::cin >> n;
    while (n--)
    {
        std::string country;
        std::cin >> country;
        ++list[country];
        std::string rest_line;
        std::getline(std::cin, rest_line);
    }
    for (const auto& e : list)
        std::cout << e.first << ' ' << e.second << '\n';
}