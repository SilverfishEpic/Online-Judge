#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::string> lines;
    std::string s;
    std::size_t max_len = 0;

    while (std::getline(std::cin, s)) {
        max_len = std::max(max_len, s.size());
        lines.push_back(std::move(s));
    }

    for (std::size_t col = 0; col < max_len; ++col) {
        for (auto r = lines.size(); r-- != 0; ) {  // safe reverse over size_t
            const auto& row = lines[r];
            std::cout << (col < row.size() ? row[col] : ' ');
        }
        std::cout << '\n';
    }
}
