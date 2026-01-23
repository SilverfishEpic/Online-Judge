#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::array<char, 101>> matrix;
    std::string s;
    int maxLen = 0;

    while (std::getline(std::cin, s)) {
        std::array<char, 101> buf;
        buf.fill(' ');  // 用空白補齊，符合題意

        int n = std::min<int>((int)s.size(), (int)buf.size());
        std::copy_n(s.begin(), n, buf.begin());

        maxLen = std::max(maxLen, n);
        matrix.emplace_back(buf);
    }

    // 旋轉：輸出 maxLen 行（不是固定 101）
    for (int j = 0; j < maxLen; ++j) {
        for (int i = (int)matrix.size() - 1; i >= 0; --i) {
            std::cout << matrix[i][j];
        }
        std::cout << '\n';
    }
}
