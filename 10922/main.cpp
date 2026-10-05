#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string number;
    while (std::cin >> number)
    {
        if (number == "0") break;
        std::cout << number;
        unsigned degree(0), sum;
        // here i just want to write less code, but if want optimization,
        // i think except first iteraion, can use int to count degree,
        // and check not multiple result earlier
        do
        {
            sum = 0;
            for (auto const& ch : number)
                sum += ch - '0';
            ++degree;
            number = std::to_string(sum);
        } while (sum > 9);
        if (sum == 9) std::cout << " is a multiple of 9 and has 9-degree " << degree << ".\n";
        else std::cout << " is not a multiple of 9.\n";
    }
}