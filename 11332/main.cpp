#include <iostream>

unsigned long func(unsigned long n)
{
    if (n < 10) return n;
    unsigned long sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return func(sum);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long n;
    while (std::cin >> n)
    {
        if (!n) return 0;
        std::cout << func(n) << '\n';
    }
}