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
        int diff = 0;
        short sign = 1;
        for (const auto& d : N)
        {
            diff += sign * (d - '0');
            sign *= -1;
        }
        std::cout << N << " is " << (diff % 11 ? "not " : "")
            << "a multiple of 11.\n";
    }
}