#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    bool is_right = false;
    while (std::getline(std::cin, str))
    {
        for (const auto& ch : str)
            if (ch == '"')
            {
                std::cout << (is_right ? "''" : "``");
                is_right = !is_right;
            }
            else std::cout << ch;
        std::cout << '\n';
    }
}