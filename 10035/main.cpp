#include <iostream>
#include <string>

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
            bool isnot_ae = a_iter != a.crend();
            bool isnot_be = b_iter != b.crend();

            int ai = isnot_ae ? *a_iter - '0' : 0,
                bi = isnot_be ? *b_iter - '0' : 0;
            is_carry_on = ai + bi + is_carry_on >= 10;
            carry_count += is_carry_on;

            if (isnot_ae) ++a_iter;
            if (isnot_be) ++b_iter;
        }
        if (!carry_count)
            std::cout << "No carry operation.\n";
        else if (carry_count == 1)
            std::cout << "1 carry operation.\n";
        else std::cout << carry_count << " carry operations.\n";
    }
}