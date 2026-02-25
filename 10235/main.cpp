#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string N;
    while (std::cin >> N)
    {
        unsigned long const Nul(std::stoul(N));
        auto isPrime = [](unsigned long x){
            if (x < 2) return false;
            for (unsigned long i=2; i*i<=x; ++i)
                if (x % i == 0) return false;
            return true;
        };
        bool const is_prime(isPrime(Nul));
        std::reverse(N.begin(), N.end());
        unsigned long const N2ul(std::stoul(N));
        // when after reverse is the same, should not count as emirp
        if (is_prime && Nul != N2ul && isPrime(N2ul)) std::cout << Nul << " is emirp.\n";
        else if (is_prime) std::cout << Nul << " is prime.\n";
        else std::cout << Nul << " is not prime.\n";
    }
}