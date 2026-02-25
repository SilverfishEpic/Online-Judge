#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned short N;
    std::cin >> N;
    for (unsigned short p = 0; p++ != N;)
    {
        std::string S1, S2;
        std::cin >> S1 >> S2;
        unsigned long S1lu = 0, S2lu = 0;
        for (const auto& ch : S1) S1lu = S1lu * 2 + ch - '0';
        for (const auto& ch : S2) S2lu = S2lu * 2 + ch - '0';
        while ((S1lu %= S2lu) && (S2lu %= S1lu)) ;
        std::cout << "Pair #" << p << ": ";
        if (S1lu + S2lu - 1)
            std::cout << "All you need is love!\n";
        else std::cout << "Love is not all you need!\n";
    }
}