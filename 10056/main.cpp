#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int S;
    std::cin >> S;
    while (S--)
    {
        int N, I;
        double p;
        std::cin >> N >> p >> I;
        if (!p)
            std::cout << "0.0000\n";
        else
            std::cout << std::fixed << std::setprecision(4)
            << std::pow(1 - p, I - 1) * p / (1 - std::pow(1 - p, N)) << '\n';
    }
}