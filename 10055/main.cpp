#include <iostream>
#include <cstdlib>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long a, b;
    while (std::cin >> a >> b)
        // 關鍵在於題目敘述中的 or vice versa，前後兩數字的大小沒有一定
        std::cout << std::llabs(a - b) << '\n';
}