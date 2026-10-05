#include <iostream>
#include <vector>
#include <cstdlib>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned short T;
    std::cin >> T;
    while (T--)
    {
        short M, N, Q;
        std::cin >> M >> N >> Q;
        std::vector<std::vector<char>> rect(M);
        for (auto& row : rect)
        {
            row.resize(N);
            for (auto& ch : row)
                std::cin >> ch;
        }
        std::cout << M << ' ' << N << ' ' << Q << '\n';
        while (Q--)
        {
            short r, c;
            std::cin >> r >> c;
            short k = 0;
            bool con(true);
            while (con && ++k)
                for (short i = r - k; con && i <= r + k; ++i)
                    for (short j = c - k; con && j <= c + k; ++j)
                        if (std::abs(i - r) != k && std::abs(j - c) != k)
                            continue;
                        else try
                        {
                            if (rect.at(i).at(j) != rect[r][c]) con = false;
                        }
                        catch(const std::exception& e)
                        {
                            con = false;
                        }
            std::cout << 1 + --k * 2 << '\n';
        }
    }
}