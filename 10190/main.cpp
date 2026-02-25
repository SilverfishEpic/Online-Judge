#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long n, m;
    while (std::cin >> n >> m)
    {
        if (m <= 1 || n <= 1)
        {
            std::cout << "Boring!\n";
            continue;
        }
        std::string buffer;
        while (n != 1)
        {
            if (n % m)
            {
                std::cout << "Boring!\n";
                buffer.clear();
                break;
            }
            buffer += std::to_string(n) + " ";
            n /= m;
        }
        if (n == 1)
            std::cout << buffer << 1 << '\n';
    }
}