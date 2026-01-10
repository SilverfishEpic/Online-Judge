#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main()
{
    // 加速 I/O：關掉 iostream 與 stdio 的同步（競程常用）
    std::ios::sync_with_stdio(false);

    // 解除 cin 與 cout 的綁定，避免每次輸入都強制刷新輸出（更快）
    std::cin.tie(nullptr);

    std::size_t test_case; // test cases 數量

    // 逐個處理每個 test case
    while (test_case--)
    {
        unsigned short r;         // 親戚人數（0 < r < 500）
        std::cin >> r; // 讀入人數

        // 建立大小為 r 的陣列，用來存每個親戚的街號
        std::vector<unsigned short> a(r);

        // 讀入 r 個街號（cin >> 會自動跨行讀取，不必管分行）
        for (unsigned short i = 0; i < r; ++i)
            std::cin >> a[i];

        // 排序街號，方便取中位數
        std::sort(a.begin(), a.end());

        // 中位數位置：r/2（0-based）
        // 中位數能使 sum |si - x| 最小（最佳點）
        auto med = a[r / 2];

        unsigned sum = 0;

        // 對每個街號計算到中位數的距離並累加
        for (auto x : a)
            sum += std::abs(x - med);

        // 輸出該 test case 的最小總距離
        std::cout << sum << std::endl;
    }
}
