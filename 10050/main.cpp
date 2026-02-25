#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned T;
    std::cin >> T;
    while (T--)
    {
        unsigned short N;
        std::cin >> N;
        std::vector<bool> days(N);
        unsigned short P;
        std::cin >> P;
        for (unsigned short i = 0; i != P; ++i)
        {
            unsigned h;
            std::cin >> h;
            unsigned short const step = h % 7;
            unsigned short weekday = (h - 1) % 7;
            for (unsigned m = h - 1; m < N; m += h)
            {
                if (5 != weekday && 6 != weekday)
                    days[m] = true;
                weekday += step;
                if (weekday >= 7) weekday -= 7;
            }
        }
        unsigned sum = 0;
        for (const auto& n : days) sum += n;
        std::cout << sum << '\n';
    }
}