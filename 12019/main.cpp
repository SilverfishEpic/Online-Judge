#include <iostream>
#include <array>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<std::string, 7> weekday {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday",
    };
    std::array<int, 12> month {
        10, 21, -1, 4, 9, 6,
        11, 8, 5, 10, 7, 12,
    };
    int t;
    std::cin >> t;
    while (t--)
    {
        int M, D;
        std::cin >> M >> D;
        if (M == 3)
        {
            --M;
            D += 28;
        }
        std::cout << weekday[((D - month[M - 1]) % 7 + 7) % 7] << '\n';
    }
}