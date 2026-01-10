// in fact, this problem didn't need to shape as LCS problem, can use easier solution.

#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <cctype>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b;
    while (std::getline(std::cin, a) && std::getline(std::cin, b))
    {
        std::array<unsigned short, 26> a_count { 0 }, b_count { 0 };
        for (const auto& ch : a)
            if (std::islower(static_cast<unsigned char>(ch))) ++a_count[ch - 'a'];
        for (const auto& ch : b)
            if (std::islower(static_cast<unsigned char>(ch))) ++b_count[ch - 'a'];
        for (auto i = 0; i != 26; ++i)
        {
            unsigned short count = std::min(a_count[i], b_count[i]);
            while (count--)
                std::cout << static_cast<char>('a' + i);
        }
        std::cout << '\n';
    }
}