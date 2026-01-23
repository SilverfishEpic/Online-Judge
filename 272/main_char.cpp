#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char ch;
    bool is_right = false;
    while (std::cin.get(ch))
        if (ch == '"')
        {
            std::cout << (is_right ? "''" : "``");
            is_right = !is_right;
        }
        else std::cout << ch;
}