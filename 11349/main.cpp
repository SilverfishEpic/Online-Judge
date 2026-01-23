#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned T;
    std::cin >> T;
    for (unsigned t = 1; t <= T; ++t)
    {
        char discard;
        unsigned n;
        std::cin >> discard >> discard >> n;
        std::vector<std::vector<long>> matrix(n);
        bool chk = true;
        for (decltype(n) i = 0; i != n; ++i)
        {
            matrix[i].resize(n);
            for (decltype(n) j = 0; j != n; ++j)
            {
                std::cin >> matrix[i][j];
                decltype(i) i_inv = n - i - 1,
                    j_inv = n - j - 1;
                // Definition: Symmetric matrix is such a matrix that all elements
                // of it are **non-negative** and symmetric with relation to the center of this matrix.
                if (matrix[i][j] < 0 ||
                    (i > i_inv || i == i_inv && j > j_inv) && matrix[i][j] != matrix[i_inv][j_inv])
                    chk = false;
            }
        }
        std::cout << "Test #" << t << ": " << (chk ? "Symmetric" : "Non-symmetric") << ".\n";
    }
}
