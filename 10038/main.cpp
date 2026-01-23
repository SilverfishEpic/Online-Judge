#include <iostream>
#include <vector>
#include <cstdlib>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n)
    {
        std::vector<bool> seen(--n, false);
        bool chk = true;
        int prev;
        std::cin >> prev;
        while(n--)
        {
            int curr;
            std::cin >> curr;
            if (chk)
            {
                const int diff = std::abs(curr - prev);
                if (diff && !seen[diff - 1])
                {
                    seen[diff - 1] = true;
                    prev = curr;
                }
                else
                    chk = false;
            }
        }
        for (auto iter = seen.cbegin(); chk && iter != seen.cend(); ++iter)
            if (!*iter)
                chk = false;
        std::cout << (chk ? "Jolly\n" : "Not jolly\n");
    }
}