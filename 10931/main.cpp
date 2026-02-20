#include <iostream>
#include <bitset>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long I;
    while (std::cin >> I)
    {
        if (!I) break;
        std::bitset<32> I_bitset(I);
        const auto& I_string = I_bitset.to_string();
        std::cout << "The parity of " << I_string.substr(I_string.find('1'))
            << " is " << I_bitset.count() << " (mod 2).\n";
    }
}