// NOT WORKING, plz use refactor version
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x;
    while (std::cin >> x)
    {
        std::vector<long> poly;
        std::string buffer;
        std::cin >> std::ws;
        std::getline(std::cin, buffer);
        std::stringstream strin(buffer);
        long a;
        while (strin >> a)
            poly.push_back(std::move(a));
        long result = 0;
        auto iter = poly.begin();
        for (int i = poly.size() - 1; i != 0; --i, ++iter)
            result += *iter * i * static_cast<long>(std::powl(x, i - 1)); // UVa doesn't have powl
        std::cout << result << '\n';
    }
}