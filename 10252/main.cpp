#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::string a, b;
    while (std::getline(std::cin, a) && std::getline(std::cin, b))
    {
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        std::vector<std::vector<std::pair<int, char>>> cs;
        cs.resize(a.size() + 1);
        for (auto& col : cs)
            col.resize(b.size() + 1, {0, ' '});
        for (auto i = 0; i != a.size(); ++i)
            for (auto j = 0; j != b.size(); ++j)
            {
                int chk = 0;
                if (a[i] == b[j]) chk = 1;
                cs[i + 1][j + 1] = {cs[i][j].first + chk, 's'};
                if (cs[i][j + 1].first > cs[i + 1][j + 1].first)
                    cs[i + 1][j + 1] = {cs[i][j + 1].first, 't'};
                else if (cs[i + 1][j].first > cs[i + 1][j + 1].first)
                    cs[i + 1][j + 1] = {cs[i + 1][j].first, 'l'};
            }
#ifdef DEBUG
        for (const auto& col : cs)
        {
            for (const auto& e : col)
                std::cout << e.first << ' ' << e.second << ' ';
        std::cout << '\n';
        }
#endif
        auto i = cs.size() - 1;
        auto j = cs[0].size() - 1;
        std::string ans;
        while (i && j)
        {
            auto current = cs[i][j];
            if (current.second == 's') --i, --j;
            else if (current.second == 't') --i;
            else if (current.second == 'l') --j;
            if (current.first != cs[i][j].first) ans.push_back(a[i]);
        }
        std::sort(ans.begin(), ans.end());
        std::cout << ans << '\n';
    }
}