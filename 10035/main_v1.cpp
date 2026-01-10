#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b;
    while (std::cin >> a >> b)
    {
        if (a == "0" && b == "0")
            break;
        unsigned short carry_count = 0;
        auto a_iter = a.crbegin();
        auto b_iter = b.crbegin();
        bool is_carry_on = false;
        while (a_iter != a.crend() || b_iter != b.crend())
        {
            int ai = a_iter != a.crend() ? *a_iter - '0' : 0,
                bi = b_iter != b.crend() ? *b_iter - '0' : 0;
            if (ai + bi + is_carry_on >= 10)
                ++carry_count, is_carry_on = true;
            else is_carry_on = false;
            if (a_iter != a.crend())
                ++a_iter;
            if (b_iter != b.crend())
                ++b_iter;
        }
        std::cout << carry_count << '\n';
    }
}