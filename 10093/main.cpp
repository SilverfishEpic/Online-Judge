#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const std::string sym("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    constexpr int upper = 'A' - 10;
    constexpr int lower = 'a' - 36;
    std::string line;
    std::cin >> std::ws;
    while(std::getline(std::cin, line))
    {
        int N = sym.size();
        while (line.find(sym[--N]) == line.npos) ;
        if (N < 1) N = 1;
        bool chk = true;
        while (N < sym.size() && chk)
        {
            unsigned R = 0;
            for (const auto& ch : line)
                // this problem could have signed symbol or whitespace
                if (std::isdigit(ch)) R = (R + ch - '0') % N;
                else if (std::isupper(ch)) R = (R + ch - upper) % N;
                else if (std::islower(ch)) R = (R + ch - lower) % N;
            if (R) ++N;
            else chk = false;`
        }
        if (chk) std::cout << "such number is impossible!\n";
        else std::cout << ++N <<'\n';
    }
}