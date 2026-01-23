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
        std::string line;
        std::cin >> std::ws;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        long a;
        while (ss >> a) poly.emplace_back(std::move(a));
        
        long n = poly.size() - 1;          // polynomial degree
        long ans = 0;
        // Evaluate derivative at x using Horner:
        // ans = (((a0*n)*x + a1*(n-1))*x + ... + a_{n-1}*1)
        for (long j = 0; j < n; j++)
            ans = ans * x + poly[j] * (n - j);
        std::cout << ans << '\n';
    }
}