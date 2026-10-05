#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main ()
{
    std::string buffer;
    bool first = true;
    while (std::getline(std::cin, buffer))
    {
        std::unordered_map<unsigned char, unsigned short> freq;
        for (const auto& ch : buffer) ++freq[ch];
        using Ch_F = std::pair<unsigned char, unsigned short>;
        std::vector<Ch_F> freq_vec(freq.begin(), freq.end());
        sort(freq_vec.begin(), freq_vec.end(), [](const Ch_F& a, const Ch_F& b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first); //fixed
        });
        if (!first) std::cout << '\n'; // fixed
        first = false;
        for (const auto& e : freq_vec) if (e.second)
            std::cout << static_cast<unsigned short>(e.first) << ' ' << e.second << '\n';
    }
}