#include <iostream>
#include <string>
#include <iterator>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string N;
    while (std::cin >> N)
    {
        if (N == "0") break;
        int odd_digit = 0, even_digit = 0;
        for (auto iter = N.cbegin(); iter != N.cend(); ++iter)
        {
            odd_digit += *iter - '0';
            if (std::next(iter) == N.cend()) break;
            even_digit += *++iter - '0';
        }
        std::cout << N << " is " << (odd_digit - even_digit % 11 ? "not " : "")
            << "a multiple of 11.\n";
    }
}