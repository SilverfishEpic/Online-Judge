#include <iostream>
#include <vector>
#include <set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned T = 0;
    unsigned short N;
    while (std::cin >> N)
    {
        bool chk = true;
        // must be int and larger than prev
        int prev = 0;
        std::vector<int> b_seq;
        std::set<int> b_sum;
        while (N--)
        {
            int b;
            std::cin >> b;
            chk = chk && prev < b;
            if (chk)
            {
                b_seq.push_back(b);
                for (const auto& e : b_seq)
                {
                    chk = b_sum.insert(b + e).second;
                    if (!chk) break;
                }
            }
            prev = b;
        }
        // extra blank space
        std::cout << "Case #" << ++T << ": It is " << (chk ? "a" : "not a") << " B2-Sequence.\n\n";
    }
}
