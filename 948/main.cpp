#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // don't need to start from 0, 1, 1...
    std::vector<unsigned long> fib { 1, 2 };
    while (fib.back() < 100000000)
        fib.push_back(fib.back() + fib[fib.size() - 2]);
    fib.pop_back();
    unsigned short N;
    std::cin >> N;
    while (N--)
    {
        unsigned long n;
        std::cin >> n;
        std::cout << n << " = ";
        bool mid_zero = false;
        bool consecutive = false;
        for (auto iter = fib.crbegin(); iter != fib.crend(); ++iter)
        {
            if (n >= *iter && !consecutive)
            {
                n -= *iter;
                mid_zero = true;
                consecutive = true;
                std::cout << 1;
            }
            else if (mid_zero)
            {
                consecutive = false;
                std::cout << 0;
            }
        }
        std::cout << " (fib)\n";
    }
}