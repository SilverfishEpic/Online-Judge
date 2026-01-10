#include <iostream>
#include <stack>
#include <array>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long long Z;
    std::array<decltype(Z), 4> arr = {100, 10, 100, 100};
    std::array<std::string, 4> unit = {
        "shata", "hajar", "lakh", "kuti"
    };
    std::stack<decltype(Z)> stack;
    while (std::cin >> Z)
    {
        int idx = 0;
        do
        {
            // std::cerr << idx << arr[idx] << '\n';
            stack.push(Z % arr[idx]);
            Z /= arr[idx];
            idx = ++idx % 4;
        } while (Z);
        while (!stack.empty())
        {
            std::cout << stack.top() << ' ';
            stack.pop();
            if (!stack.empty())
                std::cout << unit[(stack.size() - 1) % 4] << ' ';
        }
        std::cout << '\n';
    }
}