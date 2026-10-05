#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    unsigned short n, m;
    unsigned long long x(0);
    bool is_head = true;
    while (cin >> n >> m && (n || m))
    {
        vector<string> grid(n, string(m, '.'));
        for (auto& row : grid) cin >> row;
        auto compute = [&](int r, int c)
        {
            int count = 0;
            for (int dr = -1; dr <= 1; ++dr)
                for (int dc = -1; dc <= 1; ++dc)
                {
                    if (dr == 0 && dc == 0)
                        continue;
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < m &&
                        grid[nr][nc] == '*')
                        ++count;
                }
            return count;
        };
        if (!is_head) std::cout << '\n';
        is_head = false;
        cout << "Field #" << ++x << ":\n";
        for (decltype(n) j = 0; j != n; ++j)
        {
            for (decltype(m) i = 0; i!= m; ++i)
                if (grid[j][i] == '*') std::cout << '*';
                else std::cout << compute(j, i);
            std::cout << '\n';
        }
    }
}