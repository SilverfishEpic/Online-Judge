#include <iostream>
#include <utility>
#include <vector>

int main ()
{
    unsigned long long N; // test case
    std::cin >> N;
    while (N--) // 注意先後
    {
        unsigned short L;
        std::cin >> L;
        std::vector<unsigned short>state(L, 0);
        for (auto& e : state) std::cin >> e;
        unsigned S(0); // counter
        for (unsigned short i = 0; i != L; ++i) for (unsigned short j = 0; j != L - i - 1; ++j) // 注意內迴圈
            if (state[j] > state[j + 1])
            {
                std::swap(state[j], state[j + 1]);
                ++S;
            }
        std::cout << "Optimal train swapping takes " << S << " swaps.\n";
    }
}