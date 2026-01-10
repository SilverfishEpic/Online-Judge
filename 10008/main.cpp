#include <iostream>
#include <utility>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <cctype>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::array<int, 26> list{};
    std::cin >> n;
    std::cin >> std::ws;
    while (n--)
    {
        std::string line;
        std::getline(std::cin, line);
        for (const auto& ch : line)
        {
            const auto uch = static_cast<unsigned char>(ch);
            if (std::isalpha(uch))
                ++list[static_cast<char>(std::toupper(uch)) - 'A'];
        }
    }
    std::vector<std::pair<char, int>> vec;
    vec.reserve(26);
    for (auto idx = 0; idx != 26; ++idx)
        if (list[idx])
            vec.emplace_back(static_cast<char>('A' + idx), list[idx]);
    std::sort(vec.begin(), vec.end(),
        [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });
    for (const auto& e : vec)
        std::cout << e.first << ' ' << e.second << '\n';
}