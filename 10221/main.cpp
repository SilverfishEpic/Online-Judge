#include <iostream>
#include <string>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double const pi(std::acos(-1.0));
    constexpr double r(6440.0);
    double s, a;
    std::string unit;
    while (std::cin >> s >> a >> unit)
    {
        s += r;
        if (unit == "min") a /= 60.0;
        if (a > 180.0) a = 360.0 - a;
        a *= pi / 180.0;
        std::cout << std::fixed << s * a << ' ' // fixed will default set to 6 digit
            << 2.0 * s * std::sin(a / 2.0) << '\n';
    }
}