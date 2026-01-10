#include <array>
#include <cctype>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 預設：所有字元都映射到自己（包含 whitespace）
    std::array<unsigned char, 256> mp{};
    for (int i = 0; i < 256; ++i) mp[i] = static_cast<unsigned char>(i);

    // 設定映射，同時把大寫也映射到同樣結果（輸出一律是小寫那套）
    auto set = [&](unsigned char from, unsigned char to) {
        mp[from] = to;
        if (std::isalpha(from)) {
            mp[std::toupper(from)] = to;
        }
    };

    set('e','q'); set('d','a'); set('c','z'); set('r','w'); set('f','s'); set('v','x');
    set('t','e'); set('g','d'); set('b','c'); set('y','r'); set('h','f'); set('n','v');
    set('u','t'); set('j','g'); set('m','b'); set(',','n'); set('o','u'); set('l','j');
    set('.','m'); set('p','i'); set(';','k'); set('[','o'); set('\'','l'); set(']','p');

    char ch;
    while (std::cin.get(ch)) {
        std::cout << static_cast<char>(mp[static_cast<unsigned char>(ch)]);
    }
    return 0;
}
